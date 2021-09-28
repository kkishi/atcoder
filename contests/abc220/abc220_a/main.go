package main

import (
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	a, b, c := rd.Int3()
	d := (a + c - 1) / c * c
	if d <= b {
		wt.W(d)
	} else {
		wt.W(-1)
	}
}
