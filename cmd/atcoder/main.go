package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"strings"

	"github.com/kkishi/atcoder/pkg/preprocess"
)

var (
	file      = flag.String("file", "", "")
	runTest   = flag.Bool("t", false, "")
	runSubmit = flag.Bool("s", false, "")
	dbg       = flag.Bool("dbg", false, "")
)

func workspace(dir string) (string, error) {
	const ac = "atcoder"
	i := strings.Index(dir, ac)
	if i == -1 {
		return "", fmt.Errorf("failed to determine workspace for dir: %q", dir)
	}
	return dir[0 : i+len(ac)], nil
}

func preprocessIncludes(dir, base string) (string, error) {
	ws, err := workspace(dir)
	if err != nil {
		return "", err
	}
	in, err := os.OpenFile(filepath.Join(dir, base), os.O_RDONLY, 0)
	if err != nil {
		return "", err
	}
	defer in.Close()
	tmpFile, err := ioutil.TempFile(dir, "*.cc")
	if err != nil {
		return "", err
	}
	return tmpFile.Name(), preprocess.Includes(in, tmpFile, ws)
}

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
	ws, err := workspace(dir)
	if err != nil {
		return err
	}
	args := []string{"-std=c++17", "-DDEBUG", "-I" + ws}
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
	dir, base := filepath.Dir(*file), filepath.Base(*file)
	if *runSubmit {
		tempFile, err := preprocessIncludes(dir, base)
		if err != nil {
			log.Fatal("failed to preprocess includes: %s", err)
		}
		defer os.Remove(tempFile)
		base = filepath.Base(tempFile)
	}
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
