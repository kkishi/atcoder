package preprocess

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
	"path/filepath"
	"regexp"
)

var includeExp = regexp.MustCompile("^#include \"(.*\\.h)\"$")
var included = make(map[string]bool)

type preprocessor struct {
	w io.Writer

	lastPrintedLine string
}

func lookPath(file string) (string, error) {
	path := os.Getenv("CPLUS_INCLUDE_PATH")
	for _, dir := range filepath.SplitList(path) {
		path := filepath.Join(dir, file)
		if _, err := os.Stat(path); err == nil {
			return path, nil
		}
	}
	return "", fmt.Errorf("%q not found", file)
}

func (p *preprocessor) include(header string) error {
	path, err := lookPath(header)
	if err != nil {
		return err
	}
	r, err := os.OpenFile(path, os.O_RDONLY, 0)
	if err != nil {
		return err
	}
	s := bufio.NewScanner(r)
	if !s.Scan() {
		return nil
	}
	firstLine := s.Text()
	if firstLine == "#pragma once" {
		if included[header] {
			log.Printf("skipping %q for #pragma once", header)
			return nil
		}
	} else {
		if err := p.line(firstLine); err != nil {
			return err
		}
	}
	for s.Scan() {
		if err := p.line(s.Text()); err != nil {
			return err
		}
	}
	included[header] = true
	return nil
}

var stdHeaders = map[string]bool{}

func init() {
	for _, h := range stdHeaderList {
		stdHeaders[h] = true
	}
}

var stdIncludeExp = regexp.MustCompile("^#include <(.*)>$")

func isSTDHeaderInclude(l string) bool {
	m := stdIncludeExp.FindStringSubmatch(l)
	return len(m) == 2 && stdHeaders[m[1]]
}

func (p *preprocessor) line(l string) error {
	if m := includeExp.FindStringSubmatch(l); len(m) == 2 {
		return p.include(m[1])
	}
	if isSTDHeaderInclude(l) {
		return nil
	}
	p.print(l)
	return nil
}

func (p *preprocessor) print(l string) {
	if l == "" && p.lastPrintedLine == "" {
		// Cosmetic improvement: do not print empty lines consecutively.
		return
	}
	p.lastPrintedLine = l
	fmt.Fprintln(p.w, l)
}

func Includes(r io.Reader, w io.Writer) error {
	p := &preprocessor{
		w: w,
	}
	s := bufio.NewScanner(r)
	for s.Scan() {
		if err := p.line(s.Text()); err != nil {
			return err
		}
	}
	return nil
}
