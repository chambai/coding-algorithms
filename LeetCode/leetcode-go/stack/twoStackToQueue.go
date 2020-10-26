package main

import (
	"fmt"
)

type MyQueue struct {
	in  []int
	out []int
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{
		in:  make([]int, 0),
		out: make([]int, 0),
	}
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int) {
	this.in = append(this.in, x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	if len(this.out) != 0 {
		val := this.out[len(this.out)-1]
		this.out = this.out[:len(this.out)-1]
		return val
	} else {
		for len(this.in) != 0 {
			val := this.in[len(this.in)-1]
			this.in = this.in[:len(this.in)-1]
			if len(this.in) == 0 {
				return val
			} else {
				this.out = append(this.out, val)
			}
		}
	}
	return -1
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	if len(this.out) != 0 {
		return this.out[len(this.out)-1]
	} else {
		for len(this.in) != 0 {
			val := this.in[len(this.in)-1]
			this.in = this.in[:len(this.in)-1]
			this.out = append(this.out, val)
			if len(this.in) == 0 {
				return val
			}
		}
	}
	return -1
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return len(this.in) == 0 && len(this.out) == 0
}

func main() {
	s := Constructor()
	s.Push(3)
	s.Push(2)
	s.Push(5)
	s.Push(4)
	s.Push(1)
	fmt.Println(s.Pop())
	fmt.Println(s.Peek())
	fmt.Println(s.Pop())
	fmt.Println(s.Peek())
	fmt.Println(s.Empty())
}
