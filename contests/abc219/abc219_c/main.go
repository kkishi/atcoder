package main

import (
	"sort"

	"github.com/kkishi/hytk/rd"
	"github.com/kkishi/hytk/wt"
)

func main() {
	x := rd.String()
	var ord [26]int
	for i := range ord {
		ord[x[i]-'a'] = i
	}
	n := rd.Int()
	s := rd.Strings(n)
	type P struct {
		s, t string
	}
	var ans []P
	for i := range s {
		var t []byte
		for _, e := range s[i] {
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
		wt.W(e.s)
	}
}
