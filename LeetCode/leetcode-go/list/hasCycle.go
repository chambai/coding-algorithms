/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    if head == nil || head.Next == nil || head.Next.Next == nil {
        return false
    }
    front, back := head, head
    for front.Next != nil && front.Next.Next != nil {
        front = front.Next.Next
        back = back.Next
        if front == back {
            return true
        }
    }
    return false
}
