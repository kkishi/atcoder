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
	"strings"
)

var (
	file    = flag.String("file", "", "")
	inPlace = flag.Bool("w", false, "")
)

const usingNamespaceSTD = "using namespace std;"

func rewrite(r io.Reader, w io.Writer) error {
	s := bufio.NewScanner(r)
	for s.Scan() {
		l := s.Text()
		if l == "// #undef DEBUG  // Uncomment this line to forcefully disable debug print." {
			for s.Scan() {
				l = s.Text()
				if l == usingNamespaceSTD {
					break
				}
			}
			fmt.Fprintln(w, "#include \"macros.h\"\n")
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
