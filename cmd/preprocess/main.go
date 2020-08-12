package main

import (
	"bufio"
	"flag"
	"log"
	"os"

	"github.com/kkishi/atcoder/pkg/preprocess"
)

var file = flag.String("file", "", "")

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

	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	if err := preprocess.Includes(r, w); err != nil {
		log.Fatal(err)
	}
}
