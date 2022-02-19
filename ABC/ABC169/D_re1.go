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

	var n int64
	fmt.Fscan(r, &n)

	var m int64
	m = n

	prm := map[int64]int{}

	for i := int64(2); i*i <= n; i++ {
		for m%i == 0 {
			m /= i

			v := prm[i]
			prm[i] = v + 1
		}
	}

	if m != 1 {
		v := prm[m]
		prm[m] = v + 1
	}

	var ans int
	for _, v := range prm {
		var tmp, c int
		for {
			c++
			tmp += c
			if tmp == v {
				ans += c
				break
			} else if tmp > v {
				ans += c - 1
				break
			}
		}
	}

	fmt.Fprintln(w, ans)
}
