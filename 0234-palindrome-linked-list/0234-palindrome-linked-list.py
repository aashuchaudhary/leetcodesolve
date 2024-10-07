# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from typing import Optional

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # Step 1: Use two pointers (fast and slow) to find the middle of the linked list
        fast = head  # Fast pointer moves two steps at a time
        slow = head  # Slow pointer moves one step at a time

        # Traverse the list to reach the middle
        while fast and fast.next:
            fast = fast.next.next  # Fast pointer moves by 2 nodes
            slow = slow.next  # Slow pointer moves by 1 node

        # Step 2: Reverse the second half of the linked list
        prev = None  # This will hold the reversed second half
        while slow:
            tmp = slow.next  # Temporarily store the next node
            slow.next = prev  # Reverse the pointer of the current node
            prev = slow  # Move prev pointer to the current node
            slow = tmp  # Move to the next node in the original list

        # Step 3: Compare the first half with the reversed second half
        left, right = head, prev  # Left starts at the head, right starts at the beginning of the reversed half
        while right:  # Only need to check the reversed half
            if left.val != right.val:  # If the values don't match, it's not a palindrome
                return False  # Return False if a mismatch is found
            left = left.next  # Move left pointer forward
            right = right.next  # Move right pointer forward (reversed second half)

        # If all values matched, return True (it's a palindrome)
        return True
