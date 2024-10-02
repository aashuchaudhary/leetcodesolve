class Solution:
    def arrayRankTransform(self, arr):
        arr_idx = [(x, i) for i, x in enumerate(arr)]
        arr_idx.sort()
        
        ans = [0] * len(arr)
        prev = float('-inf')
        curr = 0
        
        for x, i in arr_idx:
            if x > prev:
                curr += 1
            ans[i] = curr
            prev = x
            
        return ans
