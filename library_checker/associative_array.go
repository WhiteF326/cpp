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

	var q int
	fmt.Fscan(r, &q)

	m := map[int64]int64{}

	for q > 0 {
		q--
		var t int
		fmt.Fscan(r, &t)
		if t == 0{
			var k, v int64
			fmt.Fscan(r, &k, &v)
			m[k] = v
		}else{
			var k int64
			fmt.Fscan(r, &k)
			fmt.Fprintln(w, m[k])
		}
	}
}
