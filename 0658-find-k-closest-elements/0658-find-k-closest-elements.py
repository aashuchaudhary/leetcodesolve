class Solution:
    def findClosestElements(self, arr, k, x):
        left, right = 0, len(arr) - 1
        
        # Find the position to insert x to maintain order
        while left < right:
            mid = left + (right - left) // 2
            if arr[mid] < x:
                left = mid + 1
            else:
                right = mid
        
        # Now, left is the insertion point
        start, end = left - 1, left
        
        while k > 0:
            if start < 0:
                end += 1
            elif end >= len(arr):
                start -= 1
            elif abs(arr[start] - x) <= abs(arr[end] - x):
                start -= 1
            else:
                end += 1
            
            k -= 1
        
        return sorted(arr[start + 1:end])
