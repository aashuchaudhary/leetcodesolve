# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from typing import Optional

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # Step 1: Traverse the linked list and store the values in a list
        nums = []  # List to store node values
        while head:
            nums.append(head.val)  # Append each node's value to the list
            head = head.next  # Move to the next node

        # Step 2: Initialize two pointers to check for palindrome
        l, r = 0, len(nums) - 1  # Left pointer at the start, right pointer at the end

        # Step 3: Compare values from the start and end of the list
        while l <= r:  # Continue until the pointers cross
            if nums[l] != nums[r]:  # If the values at the two pointers differ, it's not a palindrome
                return False  # Return False if it's not a palindrome
            l += 1  # Move the left pointer to the right
            r -= 1  # Move the right pointer to the left

        # Step 4: If all elements matched, return True (it's a palindrome)
        return True
