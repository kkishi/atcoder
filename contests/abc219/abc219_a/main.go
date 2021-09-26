package main

import "fmt"

func main() {
	wt := fmt.Println
	var x int
	fmt.Scan(&x)
	var ts = []int{40, 70, 90}
	for _, t := range ts {
		if x < t {
			wt(t - x)
			return
		}
	}
	wt("expert")
}
