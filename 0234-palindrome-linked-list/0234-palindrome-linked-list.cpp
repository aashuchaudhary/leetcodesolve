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
    bool isPalindrome(ListNode* head) {
        // Vector to store the values of the linked list
        vector<int> values;
        
        // Traverse the linked list and store each node's value in the vector
        while (head != nullptr) {
            values.push_back(head->val); // Append the current node's value
            head = head->next;           // Move to the next node
        }
        
        // Check for palindrome by comparing values from both ends of the vector
        for (int i = 0; i < values.size() / 2; i++) {
            // If values at the start and end don't match, it's not a palindrome
            if (values[i] != values[values.size() - i - 1]) {
                return false;  // Early return if mismatch is found
            }
        }
        
        // If no mismatches found, it is a palindrome
        return true;
    }
};
