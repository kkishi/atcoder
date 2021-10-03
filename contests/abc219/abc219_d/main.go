package main

import (
	"github.com/kkishi/hytk/md"
	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func chmin(a *int, b int) {
	if *a > b {
		*a = b
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	n, x, y := rd.Int3()
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], b[i] = rd.Int2()
	}
	const big = 1000
	dp := md.Ints2(x+1, y+1, big)
	dp[0][0] = 0
	for i := 0; i < n; i++ {
		for j := x; j >= 0; j-- {
			for k := y; k >= 0; k-- {
				chmin(&dp[min(x, j+a[i])][min(y, k+b[i])], dp[j][k]+1)
			}
		}
	}
	ans := dp[x][y]
	if ans == big {
		ans = -1
	}
	wt.W(ans)
}
