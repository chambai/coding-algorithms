/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    // cur := head
    // for cur != nil {
    //     for cur.Next != nil && cur.Val == cur.Next.Val {
    //         cur.Next = cur.Next.Next
    //     }
    //     cur = cur.Next
    // }
    // return head
    if head == nil {
        return nil
    }
    p, q := head, head.Next
    for q != nil {
        if p.Val == q.Val {
            q = q.Next
        } else {
            p.Next = q
            p = q
            q = q.Next
        }
    }
    p.Next = q
    return head
}
