package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	var s string
	fmt.Scan(&s)

	var t string
	t = s

	for i := n - 2; i >= 0; i-- {
		if s[i:i+2] == "()" {
			s = s[:i] + s[i+2:]
			i--
		}
	}

	n = len(s)

	var lt, rt int
	for i := 0; i < n; i++ {
		if s[i] == ')' {
			rt++
		} else {
			break
		}
	}
	for i := 0; i < rt; i++ {
		t = "(" + t
	}
	for i := n - 1; i >= 0; i-- {
		if s[i] == '(' {
			lt++
		} else {
			break
		}
	}
	for i := 0; i < lt; i++ {
		t += ")"
	}

	fmt.Print(t)
}
