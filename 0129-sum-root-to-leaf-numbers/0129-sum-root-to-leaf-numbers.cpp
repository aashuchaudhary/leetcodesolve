/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    void traverse(TreeNode* root, int curr) {
        if (!root) return;

        // Build the current number
        curr = curr * 10 + root->val;

        // If it's a leaf node, add the current number to the answer
        if (!root->left && !root->right) {
            ans += curr;
        }

        // Traverse the left and right subtrees
        traverse(root->left, curr);
        traverse(root->right, curr);
    }

    int sumNumbers(TreeNode* root) {
        traverse(root, 0);
        return ans;
    }
};
