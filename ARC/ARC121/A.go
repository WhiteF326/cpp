package main

import (
	"fmt"
	"sort"
)

var inf int = 1000000010
var minf int = -100000010

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	var n int
	fmt.Scan(&n)

	p := make([][]int, n)
	for i := 0; i < n; i++ {
		p[i] = make([]int, 2)
	}
	x := make([]int, n)
	y := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &y[i])
		p[i][0] = x[i]
		p[i][1] = y[i]
	}

	sort.Ints(x)
	sort.Ints(y)

	// maxv := max(x[n-1]-x[0], y[n-1]-y[0])

	res := 0

	if y[n-1]-y[0] >= x[n-1]-x[0] {
		if y[1] == y[0] || y[n-2] == y[n-1] {
			println(max(x[n-1]-x[0], y[n-1]-y[0]))
			return
		}
		res = max(y[n-1]-y[1], y[n-2]-y[0])
		nxl := inf
		mxl := minf
		nxr := inf
		mxr := minf
		for i := 0; i < n; i++ {
			if p[i][1] != y[0] {
				nxl = min(nxl, p[i][0])
				mxl = max(mxl, p[i][0])
			}
			if p[i][1] != y[n-1] {
				nxr = min(nxr, p[i][0])
				mxr = max(mxr, p[i][0])
			}
		}
		res = max(res, max(mxl-nxl, mxr-nxr))
	}

	if x[n-1]-x[0] >= y[n-1]-y[0] {
		if x[1] == x[0] || x[n-2] == x[n-1] {
			println(max(x[n-1]-x[0], y[n-1]-y[0]))
			return
		}
		res = max(res, max(x[n-1]-x[1], x[n-2]-x[0]))
		nyl := inf
		myl := minf
		nyr := inf
		myr := minf
		for i := 0; i < n; i++ {
			if p[i][1] != x[0] {
				nyl = min(nyl, p[i][1])
				myl = max(myl, p[i][1])
			}
			if p[i][1] != x[n-1] {
				nyr = min(nyr, p[i][1])
				myr = max(myr, p[i][1])
			}
		}
		res = max(res, max(myl-nyl, myr-nyr))
	}

	println(res)
}
