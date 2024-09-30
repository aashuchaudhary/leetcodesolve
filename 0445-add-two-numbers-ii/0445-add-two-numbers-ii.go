/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// Helper function to reverse a linked list
func reverseList(head *ListNode) *ListNode {
    var prev *ListNode
    current := head

    for current != nil {
        next := current.Next
        current.Next = prev
        prev = current
        current = next
    }
    return prev
}

// Function to add two numbers represented by linked lists
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    // Reverse both lists
    l1 = reverseList(l1)
    l2 = reverseList(l2)

    dummy := &ListNode{}
    current := dummy
    carry := 0

    // Traverse both reversed linked lists
    for l1 != nil || l2 != nil || carry != 0 {
        var x, y int
        if l1 != nil {
            x = l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            y = l2.Val
            l2 = l2.Next
        }

        // Calculate the sum and carry
        sum := x + y + carry
        carry = sum / 10

        // Create a new node with the sum value (mod 10) and add to the result list
        current.Next = &ListNode{Val: sum % 10}
        current = current.Next
    }

    // Reverse the result list to get the final answer in correct order
    return reverseList(dummy.Next)
}
