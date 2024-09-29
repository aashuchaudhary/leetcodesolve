# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        # Checking if the tree is null
        if root is None:
            return 0
        # Sum of left subtree, right subtree, and 1 (for root node)
        return self.countNodes(root.left) + self.countNodes(root.right) + 1
