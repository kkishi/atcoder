package main

import (
	"fmt"
	"math/big"
	"os"
)

var (
	wt  = fmt.Println
	dbg = func(a ...interface{}) (int, error) {
		return fmt.Fprintln(os.Stderr, a...)
	}
)

func main() {
	var xs string
	fmt.Scanf("%s", &xs)
	var x []int64
	for _, c := range xs {
		x = append(x, int64(c-'0'))
	}
	var m int64
	fmt.Scanf("%d", &m)
	if len(x) == 1 {
		ans := 0
		if x[0] <= m {
			ans = 1
		}
		fmt.Println(ans)
		return
	}
	f := func(base int64) bool {
		var res big.Int
		for _, c := range x {
			res.Mul(big.NewInt(base), &res).Add(big.NewInt(c), &res)
		}
		return res.Cmp(big.NewInt(m)) <= 0
	}
	d := x[0]
	for _, c := range x {
		if d < c {
			d = c
		}
	}
	if !f(d + 1) {
		fmt.Println(0)
		return
	}
	lo, hi := d+1, m+1
	for hi-lo > 1 {
		mid := (hi + lo) / 2
		if f(mid) {
			lo = mid
		} else {
			hi = mid
		}
	}
	fmt.Println(lo - d)
}
