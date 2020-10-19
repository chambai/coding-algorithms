package main

import "fmt"

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

type ResultType struct {
    SinglePath int
    MaxPath int
}

func maxPathSum(root *TreeNode) int {
    result := dfsPathSum(root)
    return result.MaxPath
}

func dfsPathSum(root *TreeNode) ResultType {
    if root == nil {
        return ResultType {
            SinglePath: 0,
            MaxPath: -(1 << 31),
        }
    }

    // divide
    l := dfsPathSum(root.Left)
    r := dfsPathSum(root.Right)

    // conquer
    result := ResultType{}

    // 单边最大值
    if l.SinglePath > r.SinglePath {
        result.SinglePath = max(l.SinglePath + root.Val, 0)
    } else {
        result.SinglePath = max(r.SinglePath + root.Val, 0)
    }

    // 两边+根最大值
    maxPath := max(l.MaxPath, r.MaxPath)
    result.MaxPath = max(maxPath, l.SinglePath + r.SinglePath + root.Val)
    return result
}

func max(a,b int) int {
    if a > b {
        return a
    }
    return b
}

func main() {
    t := &TreeNode{Val: -10}
    t.Left = &TreeNode{Val: 9}
    t.Right = &TreeNode{Val: 20}
    //t.Left.Left = &TreeNode{Val: "D"}
    //t.Left.Right = &TreeNode{Val: "E"}
    t.Right.Left = &TreeNode{Val: 15}
    t.Right.Right= &TreeNode{Val: 7}
    fmt.Printf("the max path sum is:%d\n", maxPathSum(t))
}
