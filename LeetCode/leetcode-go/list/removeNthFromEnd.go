/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    if head == nil {
        return nil
    }
    fast := head
    dummy := &ListNode{Val: 0}
    dummy.Next = head
    head = dummy

    for i := 0; i < n; i ++ {
        fast = fast.Next
    }
    for fast != nil {
        fast = fast.Next
        head = head.Next
    }
    head.Next = head.Next.Next
    return dummy.Next
}
