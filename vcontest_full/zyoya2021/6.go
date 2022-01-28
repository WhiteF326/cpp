package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n, k int
	fmt.Fscan(r, &n, &k)

	p := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Fscan(r, &p[i])
	}

	sort.Ints(p)

	var ans int
	for i := 0; i < k; i++ {
		ans += p[i]
	}

	fmt.Println(ans)
}
