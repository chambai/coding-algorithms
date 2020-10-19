package main

import "fmt"

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func insertIntoBST(root *TreeNode, val int) *TreeNode {
    if root == nil {
        root = &TreeNode{Val: val}
        return root
    }

    if root.Val > val {
        root.Left = insertIntoBST(root.Left, val)
    }
    if root.Val < val {
        root.Right = insertIntoBST(root.Right, val)
    }
    return root
}

func levelOrder(root *TreeNode) [][]int {
    result := make([][]int, 0)
    if root == nil {
        return result
    }

    queue := make([]*TreeNode, 0)
    queue = append(queue, root)

    for len(queue) != 0 {
        tmp := make([]int, 0)
        l := len(queue)
        for i := 0; i < l; i ++ {
            head := queue[0]
            tmp = append(tmp, head.Val)
            queue = queue[1:]
            if head.Left != nil {
                queue = append(queue, head.Left)
            }
            if head.Right != nil {
                queue = append(queue, head.Right)
            }
        }
        result = append(result, tmp)
    }
    return result
}

func main() {
    t := &TreeNode{Val: 4}
    t.Left = &TreeNode{Val: 2}
    t.Right = &TreeNode{Val: 7}
    t.Left.Left = &TreeNode{Val: 1}
    t.Left.Right = &TreeNode{Val: 3}
    fmt.Println(levelOrder(t))
    fmt.Printf("Insert 5: \n")
    t = insertIntoBST(t, 5)
    fmt.Println(levelOrder(t))
}
