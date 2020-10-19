/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    dummy := &ListNode{Val: 0}
    dummy.Next = head
    head = dummy

    for head.Next != nil && head.Next.Next != nil {
        p := head.Next
        q := head.Next.Next
        t := q.Next

        head.Next = q
        q.Next = p 
        p.Next = t 

        head = p 
    }
    return dummy.Next
}
