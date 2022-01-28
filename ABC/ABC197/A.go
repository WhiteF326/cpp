package main

import "fmt"

func main() {
	var s string
	fmt.Scan(&s)

	fmt.Print(s[1:] + s[0:1])
}
