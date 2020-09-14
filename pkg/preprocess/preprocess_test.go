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
			source: `#include "a.h"
#include "b.h"

int main() {
}
`,
			headers: map[string]string{
				"a.h": "#include \"b.h\"\n// a.h\n",
				"b.h": "// b.h\n",
			},
			want: `// b.h
// a.h

int main() {
}
`,
		},
		{
			source: `#include <bits/stdc++.h>
#include <vector>

int main() {
}
`,
			headers: map[string]string{},
			want: `#include <bits/stdc++.h>

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
