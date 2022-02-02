package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"os/exec"
	"time"
)

var (
	start = flag.String("start", "0000/01/01 00:00", "")
	wait  = flag.Duration("wait", 100*time.Millisecond, "")
	url   = flag.String("url", "", "")
)

func run() error {
	flag.Parse()
	t, err := time.ParseInLocation("2006/01/02 15:04", *start, time.Local)
	if err != nil {
		return err
	}
	// Add a buffer to ensure that the problems are available.
	t = t.Add(*wait)
	now := time.Now()
	if t.After(now) {
		d := t.Sub(now)
		log.Printf("Waiting for %s\n", d)
		timer := time.NewTimer(d)
		<-timer.C
	}
	cmd := exec.Command("google-chrome", *url)
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	return cmd.Run()
}

func main() {
	if err := run(); err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
}
