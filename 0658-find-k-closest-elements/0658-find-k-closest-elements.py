class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # Two pointer Approach
        left, right = 0, len(arr) - 1
        
        while right - left >= k:
            if abs(arr[left] - x) <= abs(arr[right] - x):
                right -= 1
            else:
                left += 1
        
        return arr[left:left + k]