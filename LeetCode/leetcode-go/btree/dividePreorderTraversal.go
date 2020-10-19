package main

import "fmt"

type TreeNode struct {
    Val string 
    Left *TreeNode
    Right *TreeNode
}

func main() {
    t := &TreeNode{Val: "A"}
    t.Left = &TreeNode{Val: "B"}
    t.Right = &TreeNode{Val: "C"}
    t.Left.Left = &TreeNode{Val: "D"}
    t.Left.Right = &TreeNode{Val: "E"}
    t.Right.Left = &TreeNode{Val: "F"}
    fmt.Println("PreOrder in Divide\n")
    fmt.Println(dividePreorderTraversal(t))
}

func dividePreorderTraversal(root *TreeNode) []string {
    result := make([]string, 0)
    if root == nil {
        return result
    }

    // divide
    left := dividePreorderTraversal(root.Left);
    right := dividePreorderTraversal(root.Right);

    // conquer
    result = append(result, root.Val)
    result = append(result, left...)
    result = append(result, right...)
    return result
}
