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
    int countNodes(TreeNode* root) {
        // checking tree is null or not
        if(root == NULL)
        {
            return 0;
        }
        // sum of left subtree, right subtree, and 1(for root node)
        else
        {
            return countNodes(root -> left) + countNodes(root -> right) + 1;
        }
        // one liner approach
        //return root == NULL ? 0 : countNodes(root->left) + countNodes(root->right) + 1;
    }
};