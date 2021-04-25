package main

import (
	"html"
	"encoding/json"
	"errors"
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"net/url"
	"os"
	"os/user"
	"path/filepath"
	"regexp"
	"time"

	"github.com/kkishi/atcoder/pkg/client"
)

var (
	languageID           = flag.Int("language_id", 4003, "Default: 4003 (C++ (GCC 9.2.1))")
	refreshCSRFTokenOnly = flag.Bool("refresh_csrf_token_only", false, "If true, just refreshes csrf_token and exit.")
)

func toAbs(file string) (string, error) {
	if filepath.IsAbs(file) {
		return file, nil
	}
	dir, err := os.Getwd()
	if err != nil {
		return "", err
	}
	abs, err := filepath.Abs(filepath.Join(dir, file))
	if err != nil {
		return "", err
	}
	return abs, nil
}

type solution struct {
	contestID string
	problemID string
	content   string
}

func (s *solution) submissionURL() string {
	return fmt.Sprintf("https://atcoder.jp/contests/%s/submit", s.contestID)
}

var reFile = regexp.MustCompile("contests/(.+?)/(.+?)/")

func readSolution(file string) (*solution, error) {
	var err error
	file, err = toAbs(file)
	if err != nil {
		return nil, err
	}
	m := reFile.FindStringSubmatch(file)
	if len(m) != 3 {
		return nil, fmt.Errorf("failed to recognize the problem from the file path: %q", file)
	}
	content, err := ioutil.ReadFile(file)
	if err != nil {
		return nil, err
	}
	return &solution{
		contestID: m[1],
		problemID: m[2],
		content:   string(content),
	}, nil
}

func csrfTokenCachePath() (string, error) {
	usr, err := user.Current()
	if err != nil {
		return "", err
	}
	return filepath.Join(usr.HomeDir, ".local/share/atcoder/csrf_token"), nil
}

type CSRFToken struct {
	Value      string
	CachedTime string
}

func (t *CSRFToken) cachedTime() (time.Time, error) {
	return time.Parse(time.RFC3339, t.CachedTime)
}

func getCSRFTokenFromCache() (*CSRFToken, error) {
	path, err := csrfTokenCachePath()
	if err != nil {
		return nil, err
	}
	file, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer file.Close()
	decoder := json.NewDecoder(file)
	token := CSRFToken{}
	if err := decoder.Decode(&token); err != nil {
		return nil, err
	}
	return &token, nil
}

func cacheCSRFToken(token string) error {
	path, err := csrfTokenCachePath()
	if err != nil {
		return err
	}
	if err := os.MkdirAll(filepath.Dir(path), 0755); err != nil {
		return err
	}
	file, err := os.OpenFile(path, os.O_WRONLY|os.O_CREATE|os.O_TRUNC, 0600)
	if err != nil {
		return err
	}
	defer file.Close()
	encoder := json.NewEncoder(file)
	if err := encoder.Encode(CSRFToken{
		Value:      token,
		CachedTime: time.Now().Format(time.RFC3339),
	}); err != nil {
		return err
	}
	return nil
}

var re = regexp.MustCompile(`<input type="hidden" name="csrf_token" value="(.+)" />`)

func getCSRFTokenFromWebsite(c *http.Client, sol *solution) (string, error) {
	resp, err := c.Get(sol.submissionURL())
	if err != nil {
		return "", err
	}
	defer resp.Body.Close()
	buf, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return "", err
	}
	m := re.FindSubmatch(buf)
	if len(m) != 2 {
		return "", errors.New("csrf_token not found in response")
	}
	token := html.UnescapeString(string(m[1]))
	if err := cacheCSRFToken(token); err != nil {
		// Not fatal.
		log.Println("Failed to save csrf_token to cache:", err)
	}
	return token, nil
}

func refreshCSRFToken(c *http.Client, sol *solution) error {
	token, err := getCSRFTokenFromWebsite(c, sol)
	if err != nil {
		return err
	}
	return cacheCSRFToken(token)
}

func getCSRFToken(c *http.Client, sol *solution) (string, error) {
	token, err := getCSRFTokenFromCache()
	if err != nil && !os.IsNotExist(err) {
		return "", err
	}
	if err == nil {
		t, err := token.cachedTime()
		if err == nil {
			d := time.Now().Sub(t)
			if d < time.Hour {
				log.Printf("Cached csrf_token found (age: %s)\n", d)
				return token.Value, nil
			} else {
				log.Printf("Cached csrf_token found, but it's too old (age: %s)\n", d)
			}
		}
	}
	log.Println("Getting a csrf_token from the submission page")
	return getCSRFTokenFromWebsite(c, sol)
}

func submit(c *http.Client, sol *solution) error {
	token, err := getCSRFToken(c, sol)
	if err != nil {
		return err
	}
	log.Printf("Submitting the solution (csrf_token: %s...)\n", token[0:10])
	resp, err := c.PostForm(sol.submissionURL(), url.Values{
		"data.TaskScreenName": {sol.problemID},
		"data.LanguageId":     {fmt.Sprintf("%d", *languageID)},
		"sourceCode":          {sol.content},
		"csrf_token":          {token},
	})
	if err != nil {
		return err
	}
	if resp.StatusCode != 200 {
		return fmt.Errorf("submission failed (code %d)", resp.StatusCode)
	}
	log.Println("Submission succeeded")
	return nil
}

func run() error {
	if len(flag.Args()) != 1 {
		return errors.New("solution file not specified")
	}
	sol, err := readSolution(flag.Arg(0))
	if err != nil {
		return err
	}
	c, err := client.New()
	if err != nil {
		return err
	}
	if *refreshCSRFTokenOnly {
		return refreshCSRFToken(c, sol)
	}
	return submit(c, sol)
}

func main() {
	flag.Parse()
	log.SetFlags(log.Flags() | log.Lmicroseconds)
	if err := run(); err != nil {
		log.Println("Error:", err)
		os.Exit(1)
	}
}
