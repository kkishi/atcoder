package main

import (
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	x := rd.Int()
	var ts = []int{40, 70, 90}
	for _, t := range ts {
		if x < t {
			wt.W(t - x)
			return
		}
	}
	wt.W("expert")
}
