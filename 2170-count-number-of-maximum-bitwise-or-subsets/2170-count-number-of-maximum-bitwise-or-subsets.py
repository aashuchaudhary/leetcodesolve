class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_or = 0
        for n in nums:
            max_or |= n
        
        cache = [[-1] * (max_or + 1)  for _ in range(len(nums))]

        def dfs(i,curr_or):
            nonlocal max_or
            if i == len(nums):
                return 1 if curr_or== max_or else 0
            if cache [i][curr_or] !=-1:
                return cache[i][curr_or]
            

                
            # skip i 
            return (
                dfs(i+1, curr_or) +
                dfs(i+1,curr_or | nums[i])
            )
            return cache[i][curr_or]
        return dfs(0,0)
       
