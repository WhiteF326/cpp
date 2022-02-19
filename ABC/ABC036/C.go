package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func min(a, b int64) int64 {
	if a < b {
		return a
	} else {
		return b
	}
}
func max(a, b int64) int64 {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n int
	fmt.Fscan(r, &n)

	a := make([]int, n)
	m := map[int]int{}

	for i := 0; i < n; i++ {
		fmt.Fscan(r, &a[i])
		m[a[i]] = 1
	}

	keys := make([]int, len(m))
	var idx int
	for key := range m {
		keys[idx] = key
		idx++
	}

	sort.Ints(keys)

	var ctr int
	for idx := range keys {
		m[keys[idx]] = ctr
		ctr++
	}

	for i := 0; i < n; i++ {
		fmt.Fprintln(w, m[a[i]])
	}
}
