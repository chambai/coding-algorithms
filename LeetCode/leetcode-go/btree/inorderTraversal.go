package main

import "fmt"

type TreeNode struct {
    Val string
    Left *TreeNode
    Right *TreeNode
}

func inorderRecursive(root *TreeNode) {
    if root == nil {
        return
    }
    inorderRecursive(root.Left)
    fmt.Printf("%s ", root.Val)
    inorderRecursive(root.Right)
}

func inorderNonRecursive(root *TreeNode) {
    if root == nil {
        return
    }
    var stack = make([]*TreeNode, 0)

    for root != nil || len(stack) != 0 {
        for root != nil {
            stack = append(stack, root)
            root = root.Left
        }
        top := stack[len(stack) - 1]
        fmt.Printf("%s ", top.Val)
        stack = stack[:len(stack) - 1]
        root = top.Right
    }
}

func main() {
    t := &TreeNode{Val: "A"}
    t.Left = &TreeNode{Val: "B"}
    t.Right = &TreeNode{Val: "C"}
    t.Left.Left = &TreeNode{Val: "D"}
    t.Left.Right = &TreeNode{Val: "E"}
    t.Right.Left = &TreeNode{Val: "F"}
    fmt.Println("InOrder in Recursive\n")
    inorderRecursive(t)
    fmt.Println("\nInOrder in Non-Recursive\n")
    inorderNonRecursive(t)
    fmt.Println()
}
