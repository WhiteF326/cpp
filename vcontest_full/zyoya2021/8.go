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

	a := make([]int, 3)
	for i := 0; i < 3; i++ {
		fmt.Fscan(r, &a[i])
	}
	sort.Ints(a)

	if a[0] == 5 && a[1] == 5 && a[2] == 7 {
		fmt.Fprintln(w, "YES")
	} else {
		fmt.Fprintln(w, "NO")
	}
}
