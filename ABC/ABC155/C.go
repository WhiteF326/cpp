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

	m := map[string]int{}
	var n int
	fmt.Fscan(r, &n)
	for i := 0; i < n; i++ {
		var s string
		fmt.Fscan(r, &s)
		m[s]++
	}

	var c int
	for _, v := range m {
		if v > c {
			c = v
		}
	}

	keys := make([]string, 0, len(m))
	for k := range m {
		keys = append(keys, k)
	}
	sort.Strings(keys)
	for i := 0; i < len(m); i++ {
		if m[keys[i]] == c {
			fmt.Fprintln(w, keys[i])
		}
	}
}
