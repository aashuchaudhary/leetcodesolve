class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        res = 0
        inf = float('inf')
        
        # Handling maximums
        A = [-inf] + nums + [-inf]
        s = []
        for i, x in enumerate(A):
            while s and A[s[-1]] > x:
                j = s.pop()
                k = s[-1]
                res -= A[j] * (i - j) * (j - k)
            s.append(i)
        
        # Handling minimums
        A = [inf] + nums + [inf]
        s = []
        for i, x in enumerate(A):
            while s and A[s[-1]] < x:
                j = s.pop()
                k = s[-1]
                res += A[j] * (i - j) * (j - k)
            s.append(i)
        
        return res
