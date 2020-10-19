package main

import "fmt"

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func isValidBST(root *TreeNode) bool {
    if root == nil {
        return true
    }
    result := make([]int, 0)
    inOrder(root, &result)

    for i := 0; i < len(result) - 1; i ++ {
        if result[i] >= result[i + 1] {
            return false
        }
    }
    return true
}

func inOrder(root *TreeNode, vals *[]int) {
    if root == nil {
        return
    }
    inOrder(root.Left, vals)
    *vals = append(*vals, root.Val)
    inOrder(root.Right, vals)
}

func main() {
    t := &TreeNode{Val: 1}
    t.Left = &TreeNode{Val: 2}
    t.Right = &TreeNode{Val: 3}
    t.Left.Left = &TreeNode{Val: 4}
    t.Left.Right = &TreeNode{Val: 5}
    t.Right.Left = &TreeNode{Val: 6}
    fmt.Printf("The tree is BinarySearchTree? %d\n", isValidBST(t))
}
