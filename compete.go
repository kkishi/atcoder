// go run compete.go --start="2020/06/21 14:00:00" --contest=abc171
package main

import (
	"errors"
	"flag"
	"fmt"
	"log"
	"os"
	"os/exec"
	"path"
	"strings"
	"time"
)

var (
	start       = flag.String("start", "0000/01/01 00:00:00", "")
	contest     = flag.String("contest", "", "")
	numProblems = flag.Int("num_problems", 6, "")
)

type Contest struct {
	Name     string
	Problems []string
}

func newContest(name string, numProblems int) *Contest {
	c := &Contest{
		Name: *contest,
	}
	for i := 0; i < numProblems; i++ {
		c.Problems = append(c.Problems, (string)([]byte{byte('a' + i)}))
	}
	return c
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

func createDirs(c *Contest) {
	if err := os.Mkdir(c.Name, 0750); err != nil && !os.IsExist(err) {
		exit(err)
	}
	for _, p := range c.Problems {
		dir := path.Join(c.Name, p)
		if err := os.Mkdir(dir, 0750); err != nil && !os.IsExist(err) {
			exit(err)
		}
		mainCC := path.Join(dir, "main.cc")
		if !exists(mainCC) {
			if file, err := os.Create(mainCC); err != nil {
				log.Fatal(err)
			} else {
				file.Close()
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

func downloadSamples(c *Contest) {
	for _, p := range c.Problems {
		dir := path.Join(c.Name, p)
		if testDir := path.Join(dir, "test"); exists(testDir) {
			log.Printf("%s already exists; skip", testDir)
			continue
		}
		url := fmt.Sprintf("https://atcoder.jp/contests/%s/tasks/%s_%s",
			c.Name, strings.ReplaceAll(c.Name, "-", "_"), p)
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

func main() {
	flag.Parse()

	t, err := time.ParseInLocation("2006/01/02 15:04:05", *start, time.Local)
	if err != nil {
		exit(err)
	}
	if *contest == "" {
		exit(errors.New("--contest not specified"))
	}

	c := newContest(*contest, *numProblems)
	createDirs(c)
	waitUntil(t)
	downloadSamples(c)
}
