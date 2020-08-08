package main

import (
	"bufio"
	"flag"
	"log"
	"os"

	"github.com/kkishi/atcoder/pkg/preprocess"
)

var (
	file      = flag.String("file", "", "")
	workspace = flag.String("workspace", "", "")
)

func main() {
	flag.Parse()
	if *file == "" {
		log.Fatal("--file is not specified")
	}
	if *workspace == "" {
		log.Fatal("--workspace is not specified")
	}

	r, err := os.OpenFile(*file, os.O_RDONLY, 0)
	if err != nil {
		log.Fatal(err)
	}
	defer r.Close()

	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	if err := preprocess.Includes(r, w, *workspace); err != nil {
		log.Fatal(err)
	}
}
