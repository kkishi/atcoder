package main

import (
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	s, t := rd.String2()
	wt.W(s < t)
}
