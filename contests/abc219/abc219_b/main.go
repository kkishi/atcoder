package main

import (
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	s := rd.Strings(3)
	t := rd.String()
	var ans string
	for _, e := range t {
		ans += s[e-'1']
	}
	wt.W(ans)
}
