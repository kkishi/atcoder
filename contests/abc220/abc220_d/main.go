package main

import (
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

const mod = 998244353

func main() {
	n := rd.Int()
	a := rd.Ints(n)
	dp := [10]int{}
	dp[a[0]] = 1
	for i := 1; i < n; i++ {
		ndp := [10]int{}
		for j := 0; j < 10; j++ {
			ndp[(j+a[i])%10] += dp[j]
			ndp[(j+a[i])%10] %= mod
			ndp[(j*a[i])%10] += dp[j]
			ndp[(j*a[i])%10] %= mod
		}
		dp = ndp
	}
	for _, e := range dp {
		wt.W(e)
	}
}
