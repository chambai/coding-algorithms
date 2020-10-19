package main

import "fmt"

type ListNode struct {
    Val int
    Next *ListNode
}

func deleteDuplicatesSame(head *ListNode) *ListNode {
    dummy := &ListNode{Val: 0}
    dummy.Next = head
    head = dummy

    for head.Next != nil && head.Next.Next != nil {
        if head.Next.Val == head.Next.Next.Val {
            tmp := head.Next.Val
            for head.Next != nil && head.Next.Val == tmp {
                head.Next = head.Next.Next
            }
        } else {
            head = head.Next
        }
    }
    return dummy.Next
}

func buildList(arr []int) *ListNode {
    dummy := &ListNode{Val: 0}
    head := dummy
    for i := 0; i < len(arr); i ++ {
        node := &ListNode{Val: arr[i]}
        head.Next = node
        head = head.Next
    }
    head.Next = nil
    return dummy.Next
}

func printList(head *ListNode) {
    for head != nil {
        fmt.Printf("%d ", head.Val)
        head = head.Next
    }
    fmt.Println()
}

func main() {
    arr := []int{1,2,3,3,4,5,5}
    head := buildList(arr)
    head = deleteDuplicatesSame(head)
    printList(head)
}
