package main

import (
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	p := rd.Ints(26)
	ans := make([]byte, 26)
	for i, e := range p {
		ans[i] = byte('a' + e - 1)
	}
	wt.W(string(ans))
}
