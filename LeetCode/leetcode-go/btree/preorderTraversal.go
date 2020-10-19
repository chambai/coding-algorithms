package main

import "fmt"

type TreeNode struct {
    Val string
    Left *TreeNode
    Right *TreeNode
}

func preorderRecursive(root *TreeNode) {
    if root == nil {
        return
    }
    fmt.Printf("%s ", root.Val)
    preorderRecursive(root.Left)
    preorderRecursive(root.Right)
}

func preorderNonRecursive(root *TreeNode) {
    var stack = make([]*TreeNode, 0)
    if root == nil {
        return
    }

    stack = append(stack, root)
    for len(stack) != 0 {
        top := stack[len(stack) - 1]
        fmt.Printf("%s ", top.Val)
        stack = stack[:len(stack) - 1]
        if top.Right != nil {
            stack = append(stack, top.Right)
        }
        if top.Left != nil {
            stack = append(stack, top.Left)
        }
    }
}

func main() {
    t := &TreeNode{Val: "A"}
    t.Left = &TreeNode{Val: "B"}
    t.Right = &TreeNode{Val: "C"}
    t.Left.Left = &TreeNode{Val: "D"}
    t.Left.Right = &TreeNode{Val: "E"}
    t.Right.Left = &TreeNode{Val: "F"}
    fmt.Println("PreOrder in Recursive\n")
    preorderRecursive(t)
    fmt.Println("\nPreOrder in Non-Recursive\n")
    preorderNonRecursive(t)
    fmt.Println()
}
