package main

import (
	"reflect"

	"github.com/kkishi/hytk/md"
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func chmin(a *int, b int) {
	if *a > b {
		*a = b
	}
}

func main() {
	n := rd.Int()
	read := func() [][]byte {
		var b [][]byte
		for _, e := range rd.Strings(n) {
			b = append(b, []byte(e))
		}
		return b
	}
	s := read()
	t := read()
	wt.W((func() bool {
		for i := 0; i < 4; i++ {
			f := func(v [][]byte) [][]byte {
				minr, minc := 1000, 1000
				for i := 0; i < n; i++ {
					for j := 0; j < n; j++ {
						if v[i][j] == '#' {
							chmin(&minr, i)
							chmin(&minc, j)
						}
					}
				}
				w := md.Bytes2(n, n, '.')
				for i := minr; i < n; i++ {
					for j := minc; j < n; j++ {
						w[i-minr][j-minc] = v[i][j]
					}
				}
				return w
			}
			if reflect.DeepEqual(f(s), f(t)) {
				return true
			}
			ns := md.Bytes2(n, n, 0)
			for i := 0; i < n; i++ {
				for j := 0; j < n; j++ {
					ns[j][n-1-i] = s[i][j]
				}
			}
			s = ns
		}
		return false
	})())
}
