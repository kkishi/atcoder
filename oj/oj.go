package main

import (
	"flag"
	"log"
	"os"
	"os/exec"
	"path"
	"strings"
)

var (
	file      = flag.String("file", "", "")
	runTest   = flag.Bool("t", false, "")
	runSubmit = flag.Bool("s", false, "")
	dbg       = flag.Bool("dbg", false, "")
)

func run(dir, name string, arg ...string) error {
	log.Printf("$ %s %s", name, strings.Join(arg, " "))
	cmd := exec.Command(name, arg...)
	cmd.Dir = dir
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	return cmd.Run()
}

func build(dir, base string, dbg bool) error {
	args := []string{"-std=c++17", "-DDEBUG"}
	if dbg {
		args = append(args, "-g", "-fsanitize=address,undefined")
	} else {
		args = append(args, "-O2")
	}
	return run(dir, "g++", append(args, base)...)
}

func test(dir string, dbg bool) error {
	var timeLimit string
	if dbg {
		timeLimit = "10"
	} else {
		timeLimit = "3"
	}
	return run(dir, "oj", "t", "-t", timeLimit, "--mle", "1024")
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
	if err := build(dir, base, *dbg); err != nil {
		log.Fatalf("build failed: %s", err)
	}
	if *runTest {
		if err := test(dir, *dbg); err != nil {
			log.Fatalf("test failed: %s", err)
		}
	}
	if *runSubmit {
		if err := submit(dir, base); err != nil {
			log.Fatalf("submission failed: %s", err)
		}
	}
}
