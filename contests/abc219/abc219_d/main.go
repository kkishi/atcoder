package main

import "fmt"

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
	var n, x, y int
	fmt.Scan(&n, &x, &y)
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i], &b[i])
	}
	const big = 1000
	dp := make([][]int, x+1)
	for i := range dp {
		dp[i] = make([]int, y+1)
		for j := range dp[i] {
			dp[i][j] = big
		}
	}
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
	fmt.Println(ans)
}
