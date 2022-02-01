package main

import (
	"fmt"
	"sort"
)

var cur int64
var ns []int64

func dfs(digit int64, used int) {
	if cur > 1000000000 {
		return
	}
	if used == 7 {
		ns = append(ns, cur)
	}
	for i := 0; i < 3; i++ {
		cur = cur*10 + int64(i)*2 + 3
		dfs(int64(i)*2+3, used|(1<<i))
		cur /= 10
	}
}

func main() {
	var n int64
	fmt.Scan(&n)
	dfs(0, 0)

	ns = append(ns, 1000000001)

	sort.Slice(ns, func(i, j int) bool {
		return ns[i] < ns[j]
	})
	for i := 0; i < len(ns); i++ {
		if ns[i] > n {
			fmt.Println(i)
			return
		}
	}
}
