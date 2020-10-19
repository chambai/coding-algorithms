/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    p := l1
    q := l2
    new := &ListNode{Val: 0}
    cur := new
    for p != nil && q != nil {
        if p.Val < q.Val {
            cur.Next = p
            p = p.Next
        } else {
            cur.Next = q
            q = q.Next
        }
        cur = cur.Next
    }
    if p != nil {
        cur.Next = p
    }
    if q != nil {
        cur.Next = q
    }
    return new.Next
}
