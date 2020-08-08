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
	tests := []struct {
		source  string
		headers map[string]string
		want    string
	}{
		{
			source: `#include "macros.h"
#include "pragma_once.h"
#include "pragma_once.h"

int main() {
}
`,
			headers: map[string]string{
				"macros.h":      "using ll = long long;\n",
				"pragma_once.h": "#pragma once\nconst int PI = 3;\n",
			},
			want: `using ll = long long;
const int PI = 3;

int main() {
}
`,
		},
	}

	dir, err := ioutil.TempDir("", "test")
	if err != nil {
		log.Fatal(err)
	}
	defer os.RemoveAll(dir)
	log.Printf("created a tmp dir: %q", dir)

	for _, test := range tests {
		for header, content := range test.headers {
			p := filepath.Join(dir, header)
			if err := ioutil.WriteFile(p, []byte(content), 0644); err != nil {
				log.Fatal(err)
			}
		}

		var b bytes.Buffer
		if err := Includes(bytes.NewReader([]byte(test.source)), &b, dir); err != nil {
			t.Fatal(err)
		}
		if got := b.String(); got != test.want {
			t.Errorf("got %s; want %s", got, test.want)
		}
	}
}
