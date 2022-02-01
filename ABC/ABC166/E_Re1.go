package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	m := make(map[int]int, n)
	for i := 0; i < n; i++ {
		m[a[i]+i]++
	}

	var ans int64
	for i := 0; i < n; i++ {
		ans += int64(m[i-a[i]])
	}

	fmt.Println(ans)
}
