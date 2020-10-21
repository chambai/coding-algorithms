package main

import (
	"fmt"
	"strconv"
)

func evalRPN(tokens []string) int {
	if len(tokens) == 0 {
		return 0
	}

	stack := make([]int, 0)
	for i := 0; i < len(tokens); i++ {
		switch tokens[i] {
		case "+", "-", "*", "/":
			if len(stack) < 2 {
				return -1
			}
			a := stack[len(stack)-1]
			b := stack[len(stack)-2]
			stack = stack[:len(stack)-2]
			var result int

			switch tokens[i] {
			case "+":
				result = a + b
			case "-":
				result = a - b
			case "*":
				result = a * b
			case "/":
				result = a / b
			}
			stack = append(stack, result)
		default:
			val, _ := strconv.Atoi(tokes[i])
			stack = append(stack, val)
		}
	}
	return stack[0]
}

func main() {
	str := []string{"2", "1", "+", "3", "*"}
	fmt.Println(evalRPN(str))
}
