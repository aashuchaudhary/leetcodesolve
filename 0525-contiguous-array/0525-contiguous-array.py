# 111 000

# How to know to shrink window or increase?

# Have to split, thus recursive and worse than O(n^2)

# Not every result starts at beginning, e.g.

# 111 00

# Is it possible to know exactly where

# the first 1 was, and verify that after it

# count[1] == count[0]?

# Map each index to pair (count[0], count[1])

# Use diff between counts for 0(1) lookup of what we need

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        zero, one = 0, 0
        res = 0
        diff_index = {}  # difference between count[1] and count[0] -> index
        diff_index[0] = -1  # Initialize to handle the case where the subarray starts from index 0

        for i, n in enumerate(nums):
            if n == 0:
                zero += 1
            else:
                one += 1
            
            diff = one - zero
            
            if diff not in diff_index:
                diff_index[diff] = i
            else:
                idx = diff_index[diff]
                res = max(res, i - idx)

        return res
