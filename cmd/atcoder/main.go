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
	file      = flag.String("file", "", "")
	runTest   = flag.Bool("t", false, "")
	runSubmit = flag.Bool("s", false, "")
	dbg       = flag.Bool("dbg", false, "")
	dryRun    = flag.Bool("dry_run", false, "")
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

func build(dir, base string, dbg bool) error {
	p, err := pclibPath(dir)
	if err != nil {
		return err
	}
	args := []string{"-std=c++17", "-DDEBUG", "-I" + p}
	if dbg {
		args = append(args, "-g", "-fsanitize=address,undefined")
	} else {
		args = append(args, "-O2")
	}
	return runCommand(dir, "g++", append(args, base)...)
}

func test(dir string, dbg bool) error {
	var timeLimit string
	if dbg {
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
	if err := build(dir, base, *dbg); err != nil {
		return fmt.Errorf("build failed: %w", err)
	}
	if *runTest {
		if err := test(dir, *dbg); err != nil {
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

func main() {
	flag.Parse()
	if *file == "" {
		log.Fatal("--file is not specified")
	}
	if err := run(*file); err != nil {
		log.Fatal(err)
	}
}
