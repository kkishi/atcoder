package main

import (
	"fmt"
	"strconv"
)

func main() {
	var k int
	var a, b string
	fmt.Scan(&k, &a, &b)
	A, _ := strconv.ParseInt(a, k, 64)
	B, _ := strconv.ParseInt(b, k, 64)
	fmt.Println(A * B)
}
