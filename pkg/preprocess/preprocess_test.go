package preprocess

import (
	"bytes"
	"io/ioutil"
	"log"
	"os"
	"path/filepath"
	"testing"
)

func TestPreprocessIncludes(t *testing.T) {
	src := `#include "pclib/macros.h"

int main() {
}
`
	headers := map[string]string{
		"macros.h": "using ll = long long;\n",
	}

	dir, err := ioutil.TempDir("", "test")
	if err != nil {
		log.Fatal(err)
	}
	defer os.RemoveAll(dir)

	log.Printf("created a tmp dir: %q", dir)

	if err := os.Mkdir(filepath.Join(dir, "pclib"), 0750); err != nil {
		log.Fatal(err)
	}

	for header, content := range headers {
		p := filepath.Join(dir, "pclib", header)
		if err := ioutil.WriteFile(p, []byte(content), 0644); err != nil {
			log.Fatal(err)
		}
	}

	want := `using ll = long long;

int main() {
}
`
	var b bytes.Buffer
	if err := Includes(bytes.NewReader([]byte(src)), &b, dir); err != nil {
		t.Fatal(err)
	}
	if got := b.String(); got != want {
		t.Errorf("got %s; want %s", got, want)
	}
}
