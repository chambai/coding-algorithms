/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reorderList(head *ListNode)  {
    if head == nil || head.Next == nil || head.Next.Next == nil {
        return
    }

    mid := findMidNode(head)
    tail := mid.Next
    mid.Next = nil
    tail = reverseList(tail)

    for tail != nil {
        ph := head.Next
        pt := tail.Next
        head.Next = tail
        tail.Next = ph
        tail = pt
        head = ph
    }
}

func findMidNode(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    front, back := head, head
    for front.Next != nil && front.Next.Next != nil {
        front = front.Next.Next
        back = back.Next
    }
    return back
}

func reverseList(head *ListNode) *ListNode {
    var pre *ListNode
    p := head

    for p != nil {
        q := p.Next
        p.Next = pre
        pre = p
        p = q
    }
    return pre
}
