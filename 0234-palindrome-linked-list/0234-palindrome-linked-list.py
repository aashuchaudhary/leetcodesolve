# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        values = []
        
        # Store linked list values in a list
        while head:
            values.append(head.val)
            head = head.next
        
        # Check if the list is a palindrome by comparing from both ends
        for i in range(len(values) // 2):
            if values[i] != values[-(i + 1)]:
                return False
        
        return True
