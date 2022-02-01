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

	var n int
	fmt.Fscan(r, &n)

	for i := 1; i <= 10; i++ {
		if i*1000 >= n {
			fmt.Println(i*1000 - n)
			return
		}
	}
}
