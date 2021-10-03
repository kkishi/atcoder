package main

import (
	"github.com/emirpasic/gods/trees/redblacktree"
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	l, q := rd.Int2()
	t := redblacktree.NewWithIntComparator()
	t.Put(0, nil)
	t.Put(l, nil)
	for i := 0; i < q; i++ {
		c, x := rd.Int2()
		if c == 1 {
			t.Put(x, nil)
		} else {
			f, _ := t.Floor(x)
			c, _ := t.Ceiling(x)
			wt.W(c.Key.(int) - f.Key.(int))
		}
	}
}
