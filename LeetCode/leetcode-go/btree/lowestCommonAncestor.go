package main

import "fmt"

type TreeNode struct {
    Val string
    Left *TreeNode
    Right *TreeNode
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }
    if root == p || root == q {
        return root
    }

    // divide
    l := lowestCommonAncestor(root.Left, p, q)
    r := lowestCommonAncestor(root.Right, p, q)

    // conquer
    if l != nil && r != nil {
        return root
    }
    if l != nil {
        return l
    }
    if r != nil {
        return r
    }
    return nil
}

func main() {
    t := &TreeNode{Val: "A"}
    t.Left = &TreeNode{Val: "B"}
    t.Right = &TreeNode{Val: "C"}
    //t.Left.Left = &TreeNode{Val: "D"}
    //t.Left.Right = &TreeNode{Val: "E"}
    t.Right.Left = &TreeNode{Val: "F"}
    t.Right.Right= &TreeNode{Val: "G"}
    fmt.Printf("the lowestCommonAncestor of tree is:%s\n", lowestCommonAncestor(t, t.Right.Left, t.Right.Right).Val)
}
