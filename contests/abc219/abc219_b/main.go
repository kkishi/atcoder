package main

import "fmt"

func main() {
	var s [3]string
	for i := range s {
		fmt.Scan(&s[i])
	}
	var t string
	fmt.Scan(&t)
	var ans string
	for _, e := range t {
		ans += s[e-'1']
	}
	fmt.Println(ans)
}
