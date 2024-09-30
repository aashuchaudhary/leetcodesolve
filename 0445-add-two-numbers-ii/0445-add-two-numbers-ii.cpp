/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int reverse(ListNode* head, ListNode*& prev) {
        ListNode* ptr = head;
        ListNode* next = NULL;
        int len = 0;
        while (ptr) {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
            len++;
        }
        return len;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = nullptr;
        ListNode* r2 = nullptr;

        int len1 = reverse(l1, r1);
        int len2 = reverse(l2, r2);

        if (len1 < len2) {
            swap(len1, len2);
            swap(r1, r2);
        }

        int carry = 0;
        ListNode* ptr1 = r1;
        ListNode* ptr2 = r2;
        ListNode* ans = NULL;
        ListNode* next = NULL;

        while (ptr1) {
            if (ptr2) {
                ptr1->val += ptr2->val + carry;
                ptr2 = ptr2->next;
            } 
            else {
                ptr1->val += carry;
            }

            carry = ptr1->val / 10;
            ptr1->val %= 10;

            next = ptr1->next;
            ptr1->next = ans;
            ans = ptr1;
            ptr1 = next;
        }

        if (carry == 1) {
            ListNode* newNode = new ListNode(1);
            newNode->next = ans;
            ans = newNode;
        }
        return ans;
    }
};