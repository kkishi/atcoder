package main

import (
	"bytes"
	"errors"
	"flag"
	"fmt"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"regexp"
	"strings"
	"time"

	"github.com/kkishi/atcoder/pkg/preprocess"
	"github.com/ktateish/gottani"
)

var (
	runTest         = flag.Bool("t", false, "If true, run tests using the samples. Exit if it fails.")
	runSubmit       = flag.Bool("s", false, "If true, submit the solution file.")
	dryRun          = flag.Bool("dry_run", false, "If true, do not actually submit. Useful for excersizing the end to end workflow, especially the include preprocessing.")
	compilationMode = flag.String("c", "opt", "Supported values: opt dbg prof")
	useOJSubmit     = flag.Bool("use_oj_submit", false, "Whether to use oj for submission")
)

func amalgamateCC(dir, base string) ([]byte, error) {
	r, err := os.OpenFile(filepath.Join(dir, base), os.O_RDONLY, 0)
	if err != nil {
		return nil, err
	}
	defer r.Close()
	var buf bytes.Buffer
	if err := preprocess.Includes(r, &buf); err != nil {
		return nil, err
	}
	return buf.Bytes(), nil
}

func amalgamateGo(dir string) ([]byte, error) {
	return gottani.Combine(dir, "main")
}

func amalgamate(dir, base string) (string, error) {
	ext := filepath.Ext(base)
	var buf []byte
	var err error
	switch ext {
	case ".cc":
		buf, err = amalgamateCC(dir, base)
	case ".go":
		buf, err = amalgamateGo(dir)
	default:
		err = fmt.Errorf("unsupported file extension %q", ext)
	}
	if err != nil {
		return "", fmt.Errorf("failed to amalgamate %q: %w", filepath.Join(dir, base), err)
	}
	f, err := os.CreateTemp(dir, "*"+ext)
	if err != nil {
		return "", err
	}
	_, err = bytes.NewBuffer(buf).WriteTo(f)
	return f.Name(), err
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

func buildCC(dir, base string) error {
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

func buildGo(dir, base string) error {
	return runCommand(dir, "go", "build", "-o", "a.out", base)
}

func build(dir, base string) error {
	switch filepath.Ext(base) {
	case ".cc":
		return buildCC(dir, base)
	case ".go":
		return buildGo(dir, base)
	default:
		return fmt.Errorf("failed to build %s: unsupported file extension", filepath.Join(dir, base))
	}
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
		var languageID string
		switch filepath.Ext(base) {
		case ".cc":
			languageID = "4003"
		case ".go":
			languageID = "4026"
		default:
			return fmt.Errorf("unsupported extension %q", filepath.Ext(base))
		}
		return runCommand(dir, "atcoder-submit", "-language_id", languageID, base)
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
		tempFile, err := amalgamate(dir, base)
		if err != nil {
			return fmt.Errorf("failed to preprocess includes: %w", err)
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
