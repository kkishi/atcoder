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
	w           io.Writer
	includePath string
}

func (p *preprocessor) include(header string) error {
	r, err := os.OpenFile(filepath.Join(p.includePath, header), os.O_RDONLY, 0)
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

func (p *preprocessor) line(l string) error {
	if m := includeExp.FindStringSubmatch(l); len(m) == 2 {
		return p.include(m[1])
	}
	fmt.Fprintln(p.w, l)
	return nil
}

func Includes(r io.Reader, w io.Writer, includePath string) error {
	p := &preprocessor{
		w:           w,
		includePath: includePath,
	}
	s := bufio.NewScanner(r)
	for s.Scan() {
		if err := p.line(s.Text()); err != nil {
			return err
		}
	}
	return nil
}
