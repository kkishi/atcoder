package main

import (
	"flag"
	"log"
	"os"
	"os/exec"
	"path"
)

var (
	file      = flag.String("file", "", "")
	runTest   = flag.Bool("t", false, "")
	runSubmit = flag.Bool("s", false, "")
)

func run(dir, name string, arg ...string) error {
	cmd := exec.Command(name, arg...)
	cmd.Dir = dir
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	return cmd.Run()
}

func build(dir, base string) error {
	return run(dir, "g++", "-O2", "-std=c++17", "-DDEBUG", base)
}

func test(dir string) error {
	return run(dir, "oj", "t", "-t", "2", "--mle", "1024")
}

func submit(dir, base string) error {
	return run(dir, "oj", "submit", "-y", "--no-open", base)
}

func main() {
	flag.Parse()
	if *file == "" {
		log.Fatal("--file is not specified")
	}
	dir, base := path.Dir(*file), path.Base(*file)
	if err := build(dir, base); err != nil {
		log.Fatalf("build failed: %s", err)
	}
	if *runTest {
		if err := test(dir); err != nil {
			log.Fatalf("test failed: %s", err)
		}
	}
	if *runSubmit {
		if err := submit(dir, base); err != nil {
			log.Fatalf("submission failed: %s", err)
		}
	}
}
