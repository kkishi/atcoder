package preprocess

import (
	"bytes"
	"io/ioutil"
	"log"
	"os"
	"path/filepath"
	"testing"
)

func TestIsSTDHeaderInclude(t *testing.T) {
	tests := []struct {
		line string
		want bool
	}{
		{
			line: "#include <iostream>",
			want: true,
		},
		{
			line: "#include <unknown>",
			want: false,
		},
	}
	for _, test := range tests {
		if got := isSTDHeaderInclude(test.line); got != test.want {
			t.Errorf("isSTDHeaderInclude(%q) = %t; want %t", test.line, got, test.want)
		}
	}
}

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
		t.Fatal(err)
	}
	defer os.RemoveAll(dir)
	log.Printf("created a tmp dir: %q", dir)

	pathenv := os.Getenv("CPLUS_INCLUDE_PATH")
	defer os.Setenv("CPLUS_INCLUDE_PATH", pathenv)

	if err := os.Setenv("CPLUS_INCLUDE_PATH", dir); err != nil {
		t.Fatal("Setenv failed: ", err)
	}

	for _, test := range tests {
		for header, content := range test.headers {
			p := filepath.Join(dir, header)
			if err := ioutil.WriteFile(p, []byte(content), 0644); err != nil {
				t.Fatal(err)
			}
		}

		var b bytes.Buffer
		if err := Includes(bytes.NewReader([]byte(test.source)), &b); err != nil {
			t.Fatal(err)
		}
		if got := b.String(); got != test.want {
			t.Errorf("got %s; want %s", got, test.want)
		}
	}
}
