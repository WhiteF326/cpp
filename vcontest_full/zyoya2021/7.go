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

	var a, b, c, k int64
	fmt.Fscan(r, &a, &b, &c, &k)

	var ans int64
	ans += min(a, k)
	k = max(0, k-a)
	ans += min(b, k) * 0
	k = max(0, k-b)
	ans += min(c, k) * -1

	fmt.Println(ans)
}
