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
	"regexp"
	"strings"
)

var (
	file    = flag.String("file", "", "")
	inPlace = flag.Bool("w", false, "")
)

const usingNamespaceSTD = "using namespace std;"

var readVector = regexp.MustCompile("rep\\(i, .+\\) cin >> ([^[]+)\\[i\\];")
var chmax = regexp.MustCompile("^(.*) ([^\\s]+) = (max|min)\\(([^\\s]+), (.*)$")

func rewrite(r io.Reader, w io.Writer) error {
	s := bufio.NewScanner(r)
	for s.Scan() {
		l := s.Text()
		if false {
			if l == "// #undef DEBUG  // Uncomment this line to forcefully disable debug print." {
				for s.Scan() {
					l = s.Text()
					if l == usingNamespaceSTD {
						break
					}
				}
				fmt.Fprintln(w, "#include \"macros.h\"\n")
			}
			if l == "#include \"setmin.h\"" {
				s.Scan()
				l = s.Text()
			}
			if l == "#include \"setmax.h\"" {
				s.Scan()
				l = s.Text()
			}
			l = strings.Replace(l, " in(", " rd(", 1)
			l = strings.Replace(l, " CIN(", " rd(", 1)
			l = strings.Replace(l, " out(", " wt(", 1)
			l = strings.Replace(l, " COUT(", " wt(", 1)
			l = strings.Replace(l, " REP(", " rep(", -1)
			l = strings.Replace(l, " DBG(", " dbg(", 1)
			l = strings.Replace(l, "ALL(", "all(", 1)
			l = strings.Replace(l, ".pow(", ".Pow(", -1)
			l = strings.Replace(l, "::combination(", "::Comb(", -1)
			l = strings.Replace(l, "Setmax(", "chmax(", -1)
			l = strings.Replace(l, "Setmin(", "chmin(", -1)
		}
		l = strings.Replace(l, " rd(int, ", " ints(", 1)
		l = strings.Replace(l, " rd(string, ", " strings(", 1)
		if false {
			if m := readVector.FindAllStringSubmatch(l, -1); len(m) != 0 {
				// This drops leading spaces, but we rely on later clang-format runs.
				l = fmt.Sprintf("cin >> %s;", m[0][1])
			}
			if m := chmax.FindAllStringSubmatch(l, -1); len(m) != 0 {
				for i, mi := range m[0] {
					log.Println(i, mi)
				}
				m := m[0]
				log.Println(m[2], m[4])
				if m[2] == m[4] {
					l = fmt.Sprintf("%sch%s(%s, %s", m[1], m[3], m[2], m[5])
				}
				// This drops leading spaces, but we rely on later clang-format runs.
			}
		}

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
