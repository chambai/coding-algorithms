package main

import (
	"fmt"
)

func main() {

}

func singleNumber(nums []int) int {
	// a = a^b^b^c^c
	var val int
	for _, num := range nums {
		val ^= num
	}
	return val
}

// singleNumberII
// func singleNumberII(nums []int) int {
// 	a, b := 0, 0
// 	for _, num := range nums {
// 		a = (a ^ num) & (!b)
// 		b = (b ^ num) & (!a)
// 	}
// 	return a
// }
