package main

import "fmt"

const mod = 998244353

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
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
		fmt.Println(e)
	}
}
