package main

import (
	"bufio"
	"errors"
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"regexp"
	"strings"
	"time"

	"github.com/kkishi/atcoder/pkg/preprocess"
)

var (
	runTest         = flag.Bool("t", false, "If true, run tests using the samples. Exit if it fails.")
	runSubmit       = flag.Bool("s", false, "If true, submit the solution file.")
	dryRun          = flag.Bool("dry_run", false, "If true, do not actually submit. Useful for excersizing the end to end workflow, especially the include preprocessing.")
	compilationMode = flag.String("c", "opt", "Supported values: opt dbg prof")
	useOJSubmit     = flag.Bool("use_oj_submit", false, "Whether to use oj for submission")
)

func preprocessIncludes(dir, base string) (string, error) {
	r, err := os.OpenFile(filepath.Join(dir, base), os.O_RDONLY, 0)
	if err != nil {
		return "", err
	}
	defer r.Close()

	tmpFile, err := ioutil.TempFile(dir, "*.cc")
	if err != nil {
		return "", err
	}
	w := bufio.NewWriter(tmpFile)
	defer w.Flush()

	return tmpFile.Name(), preprocess.Includes(r, w)
}

func runCommand(dir, name string, arg ...string) error {
	log.Printf("$ %s %s", name, strings.Join(arg, " "))
	cmd := exec.Command(name, arg...)
	cmd.Dir = dir
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	return cmd.Run()
}

func build(dir, base string) error {
	args := []string{"-std=c++17"}
	switch *compilationMode {
	case "opt":
		args = append(args, "-O2", "-DDEBUG")
	case "dbg":
		args = append(args, "-g", "-fsanitize=address,undefined", "-DDEBUG")
	case "prof":
		args = append(args, "-O2", "-pg")
	}
	return runCommand(dir, "g++", append(args, base)...)
}

func test(dir string) error {
	var timeLimit string
	if *compilationMode == "dbg" {
		timeLimit = "10"
	} else {
		timeLimit = "3"
	}
	return runCommand(dir, "oj", "t", "-t", timeLimit, "--mle", "1024", "-e", "0.000000001")
}

func submit(dir, base string) error {
	if *useOJSubmit {
		return runCommand(dir, "oj", "submit", "-y", "--no-open", "--wait", "0", base)
	} else {
		return runCommand(dir, "atcoder-submit", base)
	}
}

var re = regexp.MustCompile(`/contests/([^/]+)/`)

func watch(file string) error {
	m := re.FindStringSubmatch(file)
	if len(m) != 2 {
		return fmt.Errorf("failed to detect contest ID: %s", file)
	}
	contestID := m[1]
	return runCommand("", "atcoder-watch", contestID)
}

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

func run(args []string) error {
	if len(args) != 1 {
		return errors.New("solution file not specified")
	}
	file, err := toAbs(args[0])
	if err != nil {
		return err
	}
	dir, base := filepath.Dir(file), filepath.Base(file)
	if *runSubmit {
		tempFile, err := preprocessIncludes(dir, base)
		if err != nil {
			fmt.Errorf("failed to preprocess includes: %w", err)
		}
		defer os.Remove(tempFile)
		base = filepath.Base(tempFile)
	}
	if err := build(dir, base); err != nil {
		return fmt.Errorf("build failed: %w", err)
	}
	if *runTest {
		if err := test(dir); err != nil {
			return fmt.Errorf("test failed: %w", err)
		}
	}
	if *runSubmit && !*dryRun {
		if err := submit(dir, base); err != nil {
			return fmt.Errorf("submission failed: %w", err)
		}
		return watch(file)
	}
	return nil
}

func main() {
	s := time.Now()
	flag.Parse()
	log.SetFlags(log.Flags() | log.Lmicroseconds)
	err := run(flag.Args())
	d := time.Now().Sub(s)
	if err != nil {
		log.Fatalf("fail (%s): %s", d, err)
	}
	log.Printf("success (%s)", d)
}
