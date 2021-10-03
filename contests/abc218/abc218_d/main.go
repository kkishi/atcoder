package main

import (
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	n := rd.Int()
	x := make([]int, n)
	y := make([]int, n)
	type p struct {
		x, y int
	}
	m := make(map[p]bool)
	for i := 0; i < n; i++ {
		x[i], y[i] = rd.Int2()
		m[p{x[i], y[i]}] = true
	}
	var ans int
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if x[i] != x[j] && y[i] != y[j] && m[p{x[i], y[j]}] && m[p{x[j], y[i]}] {
				ans++
			}
		}
	}
	wt.W(ans / 4)
}
