class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_or = 0
        for n in nums:
            max_or |= n


        def dfs(i,curr_or):
            nonlocal max_or
            if i == len(nums):
                return 1 if curr_or== max_or else 0
                return 

                
            # skip i 
            return (
                dfs(i+1, curr_or) +
                dfs(i+1,curr_or | nums[i])
            )
        return dfs(0,0)
       
