package main

import "fmt"

type TreeNode struct {
    Val string
    Left *TreeNode
    Right *TreeNode
}

func postorderRecursive(root *TreeNode) {
    if root == nil {
        return
    }
    postorderRecursive(root.Left)
    postorderRecursive(root.Right)
    fmt.Printf("%s ", root.Val)
}

func postorderNonRecursive(root *TreeNode) {
    if root == nil {
        return
    }
    stack := make([]*TreeNode, 0)
    var lastVisited *TreeNode

    for root != nil || len(stack) != 0 {
        for root != nil {
            stack = append(stack, root)
            root = root.Left
        }
        node := stack[len(stack) - 1]
        if node.Right == nil || lastVisited == node.Right {
            stack = stack[:len(stack) - 1]
            fmt.Printf("%s ", node.Val)
            lastVisited = node
        } else {
            root = node.Right
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
    fmt.Println("PostOrder in Recursive\n")
    postorderRecursive(t)
    fmt.Println("\nPostOrder in Non-Recursive\n")
    postorderNonRecursive(t)
    fmt.Println()
}
