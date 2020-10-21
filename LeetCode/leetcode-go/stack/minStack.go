package main

import (
	"fmt"
)

type MinStack struct {
	min   []int
	stack []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		min:   make([]int, 0),
		stack: make([]int, 0),
	}
}

func (this *MinStack) Push(x int) {
	if len(this.min) == 0 || x <= this.min[len(this.min)-1] { // 注意坑，会有相同的元素
		this.min = append(this.min, x)
	}
	this.stack = append(this.stack, x)
}

func (this *MinStack) Pop() {
	if len(this.stack) != 0 {
		val := this.Top()
		this.stack = this.stack[:len(this.stack)-1]
		if len(this.min) != 0 && this.min[len(this.min)-1] == val {
			this.min = this.min[:len(this.min)-1]
		}
	}
}

func (this *MinStack) Top() int {
	if len(this.stack) != 0 {
		return this.stack[len(this.stack)-1]
	}
	return 1 << 31
}

func (this *MinStack) GetMin() int {
	if len(this.min) != 0 {
		return this.min[len(this.min)-1]
	}
	return 1 << 31
}

func main() {
	s := Constructor()
	s.Push(3)
	s.Push(2)
	s.Push(5)
	s.Push(4)
	s.Push(1)
	fmt.Println(s.Top())
	fmt.Println(s.GetMin())
	fmt.Println(s.Pop())
	fmt.Println(s.Top())
	fmt.Println(s.GetMin())
}
