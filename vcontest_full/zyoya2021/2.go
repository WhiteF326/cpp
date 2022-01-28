package main

import "fmt"

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	var n int
	fmt.Scan(&n)
	var k int
	fmt.Scan(&k)
	x := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i])
	}

	var ans int
	for i := 0; i < n; i++ {
		ans += min(x[i], k-x[i]) * 2
	}
	fmt.Println(ans)
}
