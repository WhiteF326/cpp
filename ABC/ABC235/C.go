package main

import (
	"bufio"
	"fmt"
	"os"
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

	var n, q int
	fmt.Fscan(r, &n, &q)
	a := map[int][]int{}
	for i := 0; i < n; i++ {
		var v int
		fmt.Fscan(r, &v)
		a[v] = append(a[v], i)
	}

	for t := 0; t < q; t++ {
		var x, k int
		fmt.Fscan(r, &x, &k)
		if len(a[x]) < k {
			fmt.Fprintln(w, "-1")
		} else {
			fmt.Fprintln(w, a[x][k]+1)
		}
	}
}
