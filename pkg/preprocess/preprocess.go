package preprocess

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"regexp"
)

var pclibInclude = regexp.MustCompile("^#include \"(pclib/.*\\.h)\"$")

func Includes(r io.Reader, w io.Writer, workspace string) error {
	s := bufio.NewScanner(r)
	bw := bufio.NewWriter(w)
	for s.Scan() {
		l := s.Text()
		m := pclibInclude.FindStringSubmatch(l)
		if len(m) == 0 {
			fmt.Fprintln(bw, l)
			continue
		}
		header, err := os.OpenFile(filepath.Join(workspace, m[1]), os.O_RDONLY, 0)
		if err != nil {
			return err
		}
		bw.ReadFrom(header)
		header.Close()
	}
	return bw.Flush()
}
