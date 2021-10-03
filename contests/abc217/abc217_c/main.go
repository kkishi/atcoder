package main

import (
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	n := rd.Int()
	p := rd.Ints(n)
	q := make([]int, n)
	for i, e := range p {
		q[e-1] = i + 1
	}
	wt.W(q)
}
