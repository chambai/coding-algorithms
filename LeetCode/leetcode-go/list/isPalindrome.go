/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
    if head == nil {
        return true
    }
    
    mid := findMidNode(head)
    tail := mid.Next
    mid.Next = nil
    tail = reverseList(tail)

    for tail != nil {
        if head.Val != tail.Val {
            return false
        }
        head = head.Next
        tail = tail.Next
    }
    return true
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
