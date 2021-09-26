package main

import (
	"fmt"
	"sort"
)

func main() {
	var x string
	fmt.Scan(&x)
	var ord [26]int
	for i := range ord {
		ord[x[i]-'a'] = i
	}
	// fmt.Fprint(os.Stderr, ord)
	var n int
	fmt.Scan(&n)
	s := make([]string, n)
	for i := range s {
		fmt.Scan(&s[i])
	}
	// fmt.Fprint(os.Stderr, s)
	type P struct {
		s, t string
	}
	var ans []P
	for i := range s {
		var t []byte
		for _, e := range s[i] {
			// fmt.Println(e, e-'a')
			t = append(t, byte('a'+ord[e-'a']))
		}
		ans = append(ans, P{
			s: s[i],
			t: string(t),
		})
	}
	sort.Slice(ans, func(i, j int) bool {
		return ans[i].t < ans[j].t
	})
	for _, e := range ans {
		fmt.Println(e.s)
	}
}
