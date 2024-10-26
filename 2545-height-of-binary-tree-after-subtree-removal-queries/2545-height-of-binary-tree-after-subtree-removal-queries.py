# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def __init__(self):
        self.depth = [0] * 100001
        self.levelArr = [0] * 100001
        self.max1 = [0] * 100001
        self.max2 = [0] * 100001

    def height(self, root, level):
        if not root:
            return 0
        
        # Set the level and calculate depth for the current node
        self.levelArr[root.val] = level
        self.depth[root.val] = 1 + max(self.height(root.left, level + 1), self.height(root.right, level + 1))
        
        # Update the highest and second-highest depths for the current level
        if self.max1[level] < self.depth[root.val]:
            self.max2[level] = self.max1[level]
            self.max1[level] = self.depth[root.val]
        elif self.max2[level] < self.depth[root.val]:
            self.max2[level] = self.depth[root.val]
        
        return self.depth[root.val]

    def treeQueries(self, root, queries):
        """
        :type root: Optional[TreeNode]
        :type queries: List[int]
        :rtype: List[int]
        """
        # Compute depths and max depths for each level
        self.height(root, 0)

        # Process each query
        result = []
        for q in queries:
            level = self.levelArr[q]
            
            # Calculate the result for each query based on max depths at the level
            result.append((self.max2[level] if self.max1[level] == self.depth[q] else self.max1[level]) + level - 1)
        
        return result