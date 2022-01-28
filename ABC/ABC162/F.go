package main

import (
	"fmt"
	"math"
)

func max(x, y int64) int64 {
	if x > y {
		return x
	} else {
		return y
	}
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// dp[i][j] = i 個目の数字、j 回スキップした
	dp := make([][]int64, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int64, 3)
		for j := 0; j < 3; j++ {
			dp[i][j] = math.MinInt64
		}
	}
	dp[1][0] = a[0]
	dp[2][1] = a[1]
	if n%2 == 1 {
		dp[3][2] = a[2]
	}

	// n が奇数なら 2 回までスキップできる
	// でなければ 1 回まで
	for i := 1; i < n; i++ {
		for j := 0; j < 3; j++ {
			if dp[i][j] == math.MinInt64 {
				continue
			}
			if i+2 <= n {
				dp[i+2][j] = max(dp[i+2][j], dp[i][j]+a[i+1])
			}
			if i+3 <= n && j+1 < 3 {
				dp[i+3][j+1] = max(dp[i+3][j+1], dp[i][j]+a[i+2])
			}
		}
	}

	var ans int64
	ans = math.MinInt64
	if n%2 == 1 {
		for i := 0; i <= 2; i++ {
			for j := 0; j <= 2-i; j++ {
				ans = max(ans, dp[n-i][j])
			}
		}
	} else {
		ans = max(ans, dp[n-1][0])
		ans = max(ans, dp[n][0])
		ans = max(ans, dp[n][1])
	}
	fmt.Println(dp)
	fmt.Println(ans)
}
