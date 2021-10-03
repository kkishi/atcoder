package main

import (
	"fmt"

	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	s := rd.Strings(3)
	x := int('B' + 'R' + 'G' + 'H')
	for _, e := range s {
		x -= int(e[1])
	}
	wt.W(fmt.Sprintf("A%cC", x))
}
