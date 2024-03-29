// atcoder-compete --start="2020/06/21 14:00:00" abc171
package main

import (
	"errors"
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"os/exec"
	"path"
	"path/filepath"
	"regexp"
	"strings"
	"time"

	"github.com/kkishi/atcoder/pkg/client"
)

var (
	start        = flag.String("start", "0000/01/01 00:00", "")
	wait         = flag.Duration("wait", 500*time.Millisecond, "")
	numProblems  = flag.Int("num_problems", 0, "")
	openProblems = flag.Bool("open_problems", false, "")
)

const rootDir = "contests"

type Contest struct {
	Name     string
	Problems []string
}

func exists(path string) (bool, error) {
	_, err := os.Stat(path)
	if err == nil {
		return true, nil
	}
	if os.IsNotExist(err) {
		return false, nil
	}
	return false, err
}

var tmpl = `#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
}`

func createDirs(c *Contest) error {
	for _, p := range c.Problems {
		dir := path.Join(rootDir, c.Name, p)
		if err := os.MkdirAll(dir, 0750); err != nil && !os.IsExist(err) {
			return err
		}
		mainCC := path.Join(dir, "main.cc")
		if e, err := exists(mainCC); err != nil {
			return err
		} else if !e {
			if err := ioutil.WriteFile(mainCC, []byte(tmpl), 0644); err != nil {
				return err
			}
		}
	}
	return nil
}

func waitUntilStart() error {
	t, err := time.ParseInLocation("2006/01/02 15:04", *start, time.Local)
	if err != nil {
		return err
	}
	// Add some buffer to make sure that the problems are available.
	t = t.Add(*wait)
	now := time.Now()
	if t.After(now) {
		d := t.Sub(now)
		log.Printf("%s until the contest starts\n", d)
		timer := time.NewTimer(d)
		<-timer.C
	}
	return nil
}

func openProblemsInBrowser(contestID string) error {
	cmd := exec.Command("google-chrome", fmt.Sprintf("https://atcoder.jp/contests/%s/tasks_print", contestID))
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	return cmd.Run()
}

func getProblems(c *http.Client, contestID string) ([]string, error) {
	resp, err := c.Get(fmt.Sprintf("https://atcoder.jp/contests/%s/tasks", contestID))
	if err != nil {
		return nil, err
	}
	if resp.StatusCode == 404 {
		return nil, errors.New("task page not ready")
	}
	if resp.StatusCode != 200 {
		return nil, fmt.Errorf("status: %d", resp.StatusCode)
	}
	defer resp.Body.Close()
	buf, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return nil, err
	}
	re := regexp.MustCompile(fmt.Sprintf(`"/contests/%s/tasks/(.+)"`, contestID))
	ms := re.FindAllSubmatch(buf, -1)
	seen := map[string]bool{}
	var problems []string
	for _, m := range ms {
		if len(m) != 2 {
			continue
		}
		if p := string(m[1]); !seen[p] {
			seen[p] = true
			problems = append(problems, p)
		}
	}
	return problems, nil
}

func downloadSamples(c *Contest) error {
	for _, p := range c.Problems {
		dir := path.Join(rootDir, c.Name, p)
		testDir := path.Join(dir, "test")
		if e, err := exists(testDir); err != nil {
			return err
		} else if e {
			log.Printf("%s already exists; skip", testDir)
			continue
		}
		url := fmt.Sprintf("https://atcoder.jp/contests/%s/tasks/%s", c.Name, p)
		cmd := exec.Command("oj", "d", url)
		cmd.Dir = dir
		cmd.Stdin = os.Stdin
		cmd.Stdout = os.Stdout
		cmd.Stderr = os.Stderr
		if err := cmd.Run(); err != nil {
			// oj d fails in the following cases:
			//
			// 1) There's no problem corresponding to the URL
			// 2) The problem doesn't have samples (e.g., it's an interactive problem)
			//
			// To handle both cases reasonably, on errors we just report and continue.
			log.Printf("oj d failed: %s", err)
			continue
		}
	}
	return nil
}

func refreshCSRFToken(c *Contest) error {
	mainCC := filepath.Join(rootDir, c.Name, c.Problems[0], "main.cc")
	cmd := exec.Command("atcoder-submit", "--refresh_csrf_token_only", mainCC)
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	log.Println("Refreshing csrf_token")
	return cmd.Run()
}

func run() error {
	if len(flag.Args()) != 1 {
		return errors.New("contest not specified")
	}
	contest := flag.Arg(0)
	cl, err := client.New()
	if err != nil {
		return err
	}

	var problems []string
	if *numProblems == 0 {
		ps, err := getProblems(cl, contest)
		if err != nil {
			return fmt.Errorf("failed to get problems: %s", err)
		}
		problems = ps
	} else {
		for i := 0; i < *numProblems; i++ {
			problems = append(problems, strings.Replace(contest, "-", "_", -1)+"_"+(string)([]byte{byte('a' + i)}))
		}
	}
	c := &Contest{
		Name:     contest,
		Problems: problems,
	}
	if err := createDirs(c); err != nil {
		return err
	}
	if err := waitUntilStart(); err != nil {
		return err
	}
	if *openProblems {
		if err := openProblemsInBrowser(contest); err != nil {
			// This is not a fatal error.
			log.Printf("Error while opening the problems: %s", err.Error())
		}
	}
	if err := downloadSamples(c); err != nil {
		return err
	}
	return refreshCSRFToken(c)
}

func main() {
	flag.Parse()
	log.SetFlags(log.Flags() | log.Lmicroseconds)
	if err := run(); err != nil {
		log.Println("Error:", err)
		os.Exit(1)
	}
}
