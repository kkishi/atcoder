package main

import (
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	n := rd.Int()
	wt.W(rd.String()[n-1] == 'o')
}
