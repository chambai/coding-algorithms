/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }

    dummy := &ListNode{Val: 0}
    dummy.Next = head
    cur := dummy
    var pm, pn, before, after *ListNode
    i := 1
    for cur.Next != nil {
        if i == m {
            before = cur
            pm = cur.Next
        }
        if i == n {
            after = cur.Next.Next
            pn = cur.Next
            break
        }
        cur = cur.Next
        i ++
    }
    
    var pre *ListNode
    p := pm
    for p != pn {
        q := p.Next
        p.Next = pre
        pre = p
        p = q
    }
    pn.Next = pre
    before.Next = pn
    pm.Next = after

    return dummy.Next
}
