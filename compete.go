// go run compete.go --start="2020/06/21 14:00:00" --contest=abc171
package main

import (
	"bytes"
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
	start   = flag.String("start", "0000/01/01 00:00:00", "")
	contest = flag.String("contest", "", "")
)

func exit(err error) {
	log.Print(err)
	os.Exit(1)
}

func wait(t time.Time) {
	now := time.Now()
	if t.After(now) {
		d := t.Sub(now)
		fmt.Printf("%s until the contest starts\n", d)
		timer := time.NewTimer(d)
		<-timer.C
	}
}

func download(contest string) {
	if err := os.Mkdir(contest, 0750); err != nil && !os.IsExist(err) {
		exit(err)
	}
	for i := 0; i < 6; i++ {
		problem := (string)([]byte{byte('a' + i)})
		dir := path.Join(contest, problem)
		if err := os.Mkdir(dir, 0750); err != nil && !os.IsExist(err) {
			exit(err)
		}
		mainCC := path.Join(dir, "main.cc")
		if _, err := os.Stat(mainCC); os.IsNotExist(err) {
			if file, err := os.Create(mainCC); err != nil {
				log.Fatal(err)
			} else {
				file.Close()
			}
		}
		url := fmt.Sprintf("https://atcoder.jp/contests/%[1]s/tasks/%[1]s_%[2]s",
			contest, problem)
		buf := new(bytes.Buffer)
		cmd := exec.Command("oj", "d", url)
		cmd.Dir = dir
		cmd.Stdin = os.Stdin
		cmd.Stdout = os.Stdout
		cmd.Stderr = buf
		if err := cmd.Run(); err != nil {
			if strings.Contains(buf.String(),
				"[ERROR] Failed to download since file already exists:") {
				continue
			}
			exit(err)
		}
	}
}

func emacs() {
	cmd := exec.Command("emacs", "-nw", path.Join(*contest, "a/main.cc"))
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
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

	wait(t)
	go download(*contest)
	emacs()
}
