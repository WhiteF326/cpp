package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y int
	fmt.Scan(&x, &y)

	if x > y {
		fmt.Print("0\n")
	} else {
		fmt.Print(math.Ceil((float64)(y-x) / 10.0))
	}
}
