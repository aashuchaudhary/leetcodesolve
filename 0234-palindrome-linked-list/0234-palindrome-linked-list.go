/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
    // Step 1: Convert linked list to slice
    var nums []int
    for head != nil {
        nums = append(nums, head.Val)
        head = head.Next
    }

    // Step 2: Check if slice is a palindrome
    left, right := 0, len(nums)-1
    for left < right {
        if nums[left] != nums[right] {
            return false
        }
        left++
        right--
    }

    return true
}