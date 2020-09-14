package preprocess

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"regexp"
)

var includeExp = regexp.MustCompile("^#include [\"<](.+)[\">]$")
var included = make(map[string]bool)

type preprocessor struct {
	w io.Writer

	lastPrintedLine string
}

var headerNotFound = errors.New("header not found")

func lookPath(file string) (string, error) {
	path := os.Getenv("CPLUS_INCLUDE_PATH")
	for _, dir := range filepath.SplitList(path) {
		path := filepath.Join(dir, file)
		if _, err := os.Stat(path); err == nil {
			return path, nil
		}
	}
	return "", headerNotFound
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
	if included[header] {
		return nil
	}
	included[header] = true
	for s.Scan() {
		if err := p.line(s.Text()); err != nil {
			return err
		}
	}
	return nil
}

var stdHeaders = map[string]bool{}

func init() {
	for _, h := range stdHeaderList {
		stdHeaders[h] = true
	}
}

func (p *preprocessor) line(l string) error {
	if m := includeExp.FindStringSubmatch(l); len(m) == 2 {
		header := m[1]
		if header == "bits/stdc++.h" {
			// We always include <bits/stdc++.h>.
			p.print(l)
			return nil
		}
		if stdHeaders[header] {
			// STD headers should be unnecessary because <bits/stdc++.h>, so skip.
			return nil
		}
		// Try including the header.
		if err := p.include(m[1]); err == headerNotFound {
			// If the header is not found in $CPLUS_INCLUDE_PATH, assume it's
			// provided by the system, like boost.
			p.print(l)
			return nil
		} else {
			return err
		}
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
