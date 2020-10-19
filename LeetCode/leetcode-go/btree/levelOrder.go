package main

import "fmt"

type TreeNode struct {
    Val int 
    Left *TreeNode
    Right *TreeNode
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
    t := &TreeNode{Val: 1}
    t.Left = &TreeNode{Val: 2}
    t.Right = &TreeNode{Val: 3}
    t.Left.Left = &TreeNode{Val: 4}
    t.Left.Right = &TreeNode{Val: 5}
    t.Right.Left = &TreeNode{Val: 6}
    fmt.Println("LevelOrder in Recursive\n")
    fmt.Println(levelOrder(t))
}
