# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def reverse(head):
            prev=None
            curr=head
            while curr:
                nxt=curr.next
                curr.next=prev
                prev=curr
                curr=nxt
            return prev
        l1=reverse(l1)
        l2=reverse(l2)
        carry=0
        dummy=ListNode()
        temp=dummy
        while l1 and l2:
            s=l1.val+l2.val+carry
            temp.next=ListNode(val=s%10)
            carry=s//10
            temp=temp.next
            l1=l1.next
            l2=l2.next
        l=l1 if l1 else l2
        while l:
            s=l.val+carry
            temp.next=ListNode(val=s%10)
            carry=s//10
            temp=temp.next
            l=l.next
        if carry>0: 
            temp.next=ListNode(val=carry)
            temp=temp.next
        dummy=dummy.next
        return reverse(dummy)