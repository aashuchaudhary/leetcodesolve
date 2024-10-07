/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return true
    }

    // Step 1: Find middle of the list (slow will point to the middle)
    slow, fast := head, head
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }

    // Step 2: Reverse the second half of the list
    var prev *ListNode
    for slow != nil {
        temp := slow.Next
        slow.Next = prev
        prev = slow
        slow = temp
    }

    // Step 3: Compare the first half with the reversed second half
    left, right := head, prev
    for right != nil {
        if left.Val != right.Val {
            return false
        }
        left = left.Next
        right = right.Next
    }

    return true
}