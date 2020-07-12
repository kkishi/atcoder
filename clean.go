package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"path"
	"strings"
)

func fix(contest string) {
	switch contest {
	case "abc108":
		return
	}

	p := path.Join("contests", contest)

	files, err := ioutil.ReadDir(p)
	if err != nil {
		log.Fatal(err)
	}

	for _, f := range files {
		if strings.HasPrefix(f.Name(), contest) {
			continue
		}
		correctName := contest + "_" + f.Name()
		if err := os.Rename(path.Join(p, f.Name()),
			path.Join(p, correctName)); err != nil {
			fmt.Printf("failed to rename %s -> %s\n", f.Name(), correctName)
		}
	}
}

func main() {
	files, err := ioutil.ReadDir("contests")
	if err != nil {
		log.Fatal(err)
	}

	for _, f := range files {
		fix(f.Name())
	}
}
