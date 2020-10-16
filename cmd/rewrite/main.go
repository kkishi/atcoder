package main

import (
	"bufio"
	"bytes"
	"flag"
	"fmt"
	"io"
	"io/ioutil"
	"log"
	"os"
)

var (
	file    = flag.String("file", "", "")
	inPlace = flag.Bool("w", false, "")
)

func sliceEq(a, b []string) bool {
	if len(a) != len(b) {
		return false
	}
	for i, ai := range a {
		if b[i] != ai {
			return false
		}
	}
	return true
}

func rewrite(r io.Reader, w io.Writer) error {
	s := bufio.NewScanner(r)
	var lines []string
	for s.Scan() {
		lines = append(lines, s.Text())
	}
	var rules = []struct {
		from []string
		to   []string
	}{
		{
			from: []string{
				"#include \"macros.h\"",
				"",
				"using namespace std;",
				"",
				"int main() {",
			},
			to: []string{
				"#include \"atcoder.h\"",
				"",
				"void Main() {",
			},
		},
		{
			from: []string{
				"#include \"macros.h\"",
				"#include \"modint.h\"",
				"",
				"using mint = ModInt<>;",
				"",
				"using namespace std;",
				"",
				"int main() {",
			},
			to: []string{
				"#include \"atcoder.h\"",
				"#include \"modint.h\"",
				"",
				"using mint = ModInt<>;",
				"",
				"void Main() {",
			},
		},
		{
			from: []string{
				"#include \"macros.h\"",
			},
			to: []string{
				"#include \"atcoder.h\"",
			},
		},
		{
			from: []string{
				"using namespace std;",
			},
			to: []string{
				"",
			},
		},
		{
			from: []string{
				"int main() {",
			},
			to: []string{
				"void Main() {",
			},
		},
		{
			from: []string{
				"  return 0;",
			},
			to: []string{
				"  return;",
			},
		},
		{
			from: []string{
				"    return 0;",
			},
			to: []string{
				"    return;",
			},
		},
		{
			from: []string{
				"      return 0;",
			},
			to: []string{
				"      return;",
			},
		},
	}
	for _, r := range rules {
		var newLines []string
		for i := 0; i < len(lines); i++ {
			if i+len(r.from) <= len(lines) && sliceEq(lines[i:i+len(r.from)], r.from) {
				newLines = append(newLines, r.to...)
				i += len(r.from) - 1
			} else {
				newLines = append(newLines, lines[i])
			}
		}
		lines = newLines
	}
	for _, l := range lines {
		fmt.Fprintln(w, l)
	}
	return nil
}

func main() {
	flag.Parse()
	if *file == "" {
		log.Fatal("--file is not specified")
	}

	r, err := os.OpenFile(*file, os.O_RDONLY, 0)
	if err != nil {
		log.Fatal(err)
	}
	defer r.Close()

	var w io.Writer
	if *inPlace {
		var buffer bytes.Buffer
		w = &buffer
		defer func() {
			if err := ioutil.WriteFile(*file, buffer.Bytes(), 0644); err != nil {
				log.Fatal(err)
			}
		}()
	} else {
		bw := bufio.NewWriter(os.Stdout)
		w = bw
		defer bw.Flush()
	}
	if err := rewrite(r, w); err != nil {
		log.Fatal(err)
	}
}
