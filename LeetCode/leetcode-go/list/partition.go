/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    dummyHead := &ListNode{Val: 0}
    dummyTail := &ListNode{Val: 0}
    tail := dummyTail
    dummyHead.Next = head
    head = dummyHead

    for head.Next != nil {
        if head.Next.Val < x {
            head = head.Next
        } else {
            tmp := head.Next
            head.Next = tmp.Next
            tail.Next = tmp
            tail = tail.Next
        }
    }
    tail.Next = nil
    head.Next = dummyTail.Next
    return dummyHead.Next
}
