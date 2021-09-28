package main

import (
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	n := rd.Int()
	a := rd.Ints(n)
	x := rd.Int()

	var sum int
	for _, e := range a {
		sum += e
	}
	ans := x / sum * n
	x %= sum
	for i := 0; i < n; i++ {
		x -= a[i]
		if x < 0 {
			wt.W(ans + i + 1)
			return
		}
	}
}
