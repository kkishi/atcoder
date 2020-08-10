package main

import (
	"bufio"
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
	runTest         = flag.Bool("t", false, "If true, run tests using the samples. Exit if it fails.")
	runSubmit       = flag.Bool("s", false, "If true, submit the solution file.")
	dryRun          = flag.Bool("dry_run", false, "If true, do not actually submit. Useful for excersizing the end to end workflow, especially the include preprocessing.")
	compilationMode = flag.String("c", "opt", "Supported values: opt dbg prof")
)

func pclibPath(dir string) (string, error) {
	const ac = "atcoder"
	i := strings.Index(dir, ac)
	if i == -1 {
		return "", fmt.Errorf("failed to determine the pclib path for %q", dir)
	}
	return filepath.Join(dir[0:i+len(ac)], "pclib"), nil
}

func preprocessIncludes(dir, base string) (string, error) {
	p, err := pclibPath(dir)
	if err != nil {
		return "", err
	}

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

	return tmpFile.Name(), preprocess.Includes(r, w, p)
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
	p, err := pclibPath(dir)
	if err != nil {
		return err
	}
	args := []string{"-std=c++17", "-DDEBUG", "-I" + p}
	switch *compilationMode {
	case "opt":
		args = append(args, "-O2")
	case "dbg":
		args = append(args, "-g", "-fsanitize=address,undefined")
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
	return runCommand(dir, "oj", "t", "-t", timeLimit, "--mle", "1024")
}

func submit(dir, base string) error {
	return runCommand(dir, "oj", "submit", "-y", "--no-open", base)
}

func run(file string) error {
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
	}
	return nil
}

func toAbs(file string) string {
	if filepath.IsAbs(file) {
		return file
	}
	dir, err := os.Getwd()
	if err != nil {
		log.Fatal(err)
	}
	abs, err := filepath.Abs(filepath.Join(dir, file))
	if err != nil {
		log.Fatal(err)
	}
	return abs
}

func main() {
	flag.Parse()
	args := flag.Args()
	if len(args) != 1 {
		log.Fatal("solution file not specified")
	}
	if err := run(toAbs(args[0])); err != nil {
		log.Fatal(err)
	}
}
