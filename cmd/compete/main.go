// compete --start="2020/06/21 14:00:00" --contest=abc171
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
)

var (
	start       = flag.String("start", "0000/01/01 00:00:00", "")
	contest     = flag.String("contest", "", "")
	numProblems = flag.Int("num_problems", 0, "")
)

const rootDir = "contests"

type Contest struct {
	Name     string
	Problems []string
}

func exit(err error) {
	log.Print(err)
	os.Exit(1)
}

func exists(path string) bool {
	_, err := os.Stat(path)
	if err == nil {
		return true
	}
	if os.IsNotExist(err) {
		return false
	}
	exit(err)
	return false
}

var tmpl = `#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
}`

func createDirs(c *Contest) {
	for _, p := range c.Problems {
		dir := path.Join(rootDir, c.Name, p)
		if err := os.MkdirAll(dir, 0750); err != nil && !os.IsExist(err) {
			exit(err)
		}
		mainCC := path.Join(dir, "main.cc")
		if !exists(mainCC) {
			if err := ioutil.WriteFile(mainCC, []byte(tmpl), 0644); err != nil {
				exit(err)
			}
		}
	}
}

func waitUntil(t time.Time) {
	now := time.Now()
	if t.After(now) {
		d := t.Sub(now)
		log.Printf("%s until the contest starts\n", d)
		timer := time.NewTimer(d)
		<-timer.C
	}
}

func getProblems(contest string) ([]string, bool) {
	resp, err := http.Get(fmt.Sprintf("https://atcoder.jp/contests/%s/tasks", contest))
	if err != nil {
		exit(err)
	}
	if resp.StatusCode == 404 {
		log.Print("task page not ready")
		return nil, false
	}
	if resp.StatusCode != 200 {
		exit(fmt.Errorf("status: %d", resp.StatusCode))
	}
	defer resp.Body.Close()
	buf, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		exit(err)
	}
	body := string(buf)
	re := regexp.MustCompile(fmt.Sprintf("\"/contests/%s/tasks/(.+)\"", contest))
	ms := re.FindAllStringSubmatch(body, -1)
	seen := map[string]bool{}
	var problems []string
	for _, m := range ms {
		if len(m) != 2 {
			continue
		}
		if p := m[1]; !seen[p] {
			seen[p] = true
			problems = append(problems, p)
		}
	}
	return problems, true
}

func downloadSamples(c *Contest) {
	for _, p := range c.Problems {
		dir := path.Join(rootDir, c.Name, p)
		if testDir := path.Join(dir, "test"); exists(testDir) {
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
			exit(err)
		}
	}
}

func refreshCSRFToken(c *Contest) {
	mainCC := filepath.Join(rootDir, c.Name, c.Problems[0], "main.cc")
	cmd := exec.Command("atcoder-submit", "--refresh_csrf_token_only", mainCC)
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	log.Println("Refreshing csrf_token")
	if err := cmd.Run(); err != nil {
		exit(err)
	}
}

func main() {
	flag.Parse()

	t, err := time.ParseInLocation("2006/01/02 15:04:05", *start, time.Local)
	if err != nil {
		exit(err)
	}
	if *contest == "" {
		exit(errors.New("--contest not specified"))
	}

	var problems []string
	if *numProblems == 0 {
		ps, ok := getProblems(*contest)
		if !ok {
			exit(errors.New("failed to get problems"))
		}
		problems = ps
	} else {
		for i := 0; i < *numProblems; i++ {
			problems = append(problems, strings.Replace(*contest, "-", "_", -1)+"_"+(string)([]byte{byte('a' + i)}))
		}
	}
	c := &Contest{
		Name:     *contest,
		Problems: problems,
	}
	createDirs(c)
	waitUntil(t)
	downloadSamples(c)
	refreshCSRFToken(c)
}
