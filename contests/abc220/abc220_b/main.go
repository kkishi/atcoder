package main

import (
	"strconv"

	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	k := rd.Int()
	a, b := rd.String2()
	A, _ := strconv.ParseInt(a, k, 64)
	B, _ := strconv.ParseInt(b, k, 64)
	wt.W(A * B)
}
