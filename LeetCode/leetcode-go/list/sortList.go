/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortList(head *ListNode) *ListNode {
    return mergeSort(head)
}

func mergeSort(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    mid := findMidNode(head)
    tail := mid.Next
    mid.Next = nil
    left := mergeSort(head)
    right := mergeSort(tail)
    return mergeSortTwoLists(left, right)
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

func mergeSortTwoLists(l1, l2 *ListNode) *ListNode {
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
