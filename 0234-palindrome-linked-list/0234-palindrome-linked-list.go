package main
func isPalindrome(head *ListNode) bool {
    var values []int

    // Store linked list values in a slice
    for head != nil {
        values = append(values, head.Val)
        head = head.Next
    }

    // Check if the slice is a palindrome by comparing from both ends
    for i := 0; i < len(values)/2; i++ {
        if values[i] != values[len(values)-i-1] {
            return false
        }
    }

    return true
}
