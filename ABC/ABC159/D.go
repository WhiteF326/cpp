package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n int
	fmt.Fscan(r, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &a[i])
	}

	m := map[int]int64{}
	for _, v := range a {
		m[v]++
	}

	var ans int64
	for _, v := range m {
		ans += v * (v - 1) / 2
	}

	for i := 0; i < n; i++ {
		res := ans
		res -= m[a[i]] * (m[a[i]] - 1) / 2
		res += (m[a[i]] - 1) * (m[a[i]] - 2) / 2
		fmt.Fprintln(w, res)
	}
}
