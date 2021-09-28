package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	var x int
	fmt.Scan(&x)

	var sum int
	for _, e := range a {
		sum += e
	}
	ans := x / sum * n
	x %= sum
	for i := 0; i < n; i++ {
		x -= a[i]
		if x < 0 {
			fmt.Println(ans + i + 1)
			return
		}
	}
}
