# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def canMerge(self, trees: List[TreeNode]) -> Optional[TreeNode]:
        # one last try after 90 minutes

        # got a minor hint from votrubac: "Just do what it says"

        # let's not over-think this

        # first up:
        #    trees: each is a node with 1-2 children, basically an edge list
        #           all root values are distinct
        
        # so we can follow root -> child and child->val to another tree, and so on

        # edge cases:
        #   not a BST: we can check if it's a BST with DFS
        #   cycles: covered by checking if it's a BST, if there's a loop then we'll find parent -> ... -> parent
        #           and the latter encounter of parent will not be within the exclusive value bounds required
        #
        #   not all nodes are covered: need to start with a root
        #      > no incident edges
        #      > there should be only one root
        #          and it should be connected to all of the values

        # record all child values, i.e. all nodes that will have incident edges,
        # so we can scan trees for root candidates
        children = set()
        for t in trees:
            for c in [t.left, t.right]:
                if c is None: continue
                if c.val in children: 
                    return None # duplicate value, union of trees would have duplicates
                children.add(c.val)

        # check to make sure there's only one root; if we find zero or multiple we know
        # the linking will not form a single tree
        root = None
        for t in trees:
            if t.val in children: continue # not the overall root
            else:
                if root is None: root = t
                else: 
                    return None # found two nodes with no parents, and thus would be two trees in a forest at the end
        if root is None: 
            return None


        # now there's only one possible node:
        #    > it must be a BST
        #    > it must contain all of the trees
        #        (edge case: we can have a cycle plus a separate tree rooted at root)
        tree_dict = {t.val : t for t in trees}
        unseen = {t.val for t in trees}

        def checkBST(node: Optional[TreeNode], lo: float, hi: float) -> bool:
            """
            Returns True iff node is a BST whose values are in (lo, hi) exclusive.

            side effect: removes encountered nodes from the unseen set
            """
            if node is None: return True # empty tree

            if not (lo < node.val < hi):
                return False

            unseen.discard(node.val)

            node = tree_dict.get(node.val, node) # "promote" leaves to the tree with the same value if possible

            # note that the left children must have values < node.val, and right values > node.val
            if not checkBST(node.left, lo, node.val): return False
            if not checkBST(node.right, node.val, hi): return False
            return True

        if not checkBST(root, -math.inf, math.inf):
            return None

        if len(unseen):
            return None

        # finally: if we do all the links we now know it will be a BST, so do it

        def buildBST(node: Optional[TreeNode]) -> Optional[TreeNode]:
            if node is None: return None

            if node.val in tree_dict:
                # replace this leaf node with the tree version
                tree = tree_dict[node.val]

                tree.left = buildBST(tree.left)
                tree.right = buildBST(tree.right)
                return tree
            else:
                return node

        final = buildBST(root)

        return buildBST(root)