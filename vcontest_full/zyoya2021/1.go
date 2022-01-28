package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	sort.Ints(l)

	var sum int
	for i := 0; i < n-1; i++ {
		sum += l[i]
	}

	if sum > l[n-1] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
