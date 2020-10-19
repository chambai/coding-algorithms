package main

import "fmt"

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func reverse(nums []int) {
    for i, j := 0, len(nums) - 1; i < j; i, j = i + 1, j - 1 {
        nums[i], nums[j] = nums[j], nums[i]
    }
}

func zigzagLevelOrder(root *TreeNode) [][]int {
    result := make([][]int, 0)
    if root == nil {
        return result
    }

    queue := make([]*TreeNode, 0)
    queue = append(queue, root)
    flag := false

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
        if flag {
            reverse(tmp)
        }
        result = append(result, tmp)
        flag = !flag
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
    fmt.Println(zigzagLevelOrder(t))
}
