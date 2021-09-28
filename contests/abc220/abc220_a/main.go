package main

import "fmt"

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)
	d := (a + c - 1) / c * c
	if d <= b {
		fmt.Println(d)
	} else {
		fmt.Println(-1)
	}
}
