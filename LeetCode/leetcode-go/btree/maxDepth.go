package main

import "fmt"

type TreeNode struct {
    Val string
    Left *TreeNode
    Right *TreeNode
}

func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    return max(maxDepth(root.Left), maxDepth(root.Right)) + 1
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
func main() {
    t := &TreeNode{Val: "A"}
    t.Left = &TreeNode{Val: "B"}
    t.Right = &TreeNode{Val: "C"}
    //t.Left.Left = &TreeNode{Val: "D"}
    //t.Left.Right = &TreeNode{Val: "E"}
    t.Right.Left = &TreeNode{Val: "F"}
    t.Right.Right= &TreeNode{Val: "G"}
    fmt.Printf("the depth of tree is:%d\n", maxDepth(t))
}
