package main

import (
	"fmt"
	"sort"
)

func LowerBound(array []int, target int) int {
	low, high, mid := 0, len(array)-1, 0
	for low <= high {
		mid = (low + high) / 2
		if array[mid] >= target {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return low
}

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	b := make([]int, n)
	copy(b, a)
	sort.Ints(b)

	for i := 0; i < n; i++ {
		if LowerBound(b, a[i]) == n-2 {
			fmt.Println(i + 1)
			return
		}
	}
}
