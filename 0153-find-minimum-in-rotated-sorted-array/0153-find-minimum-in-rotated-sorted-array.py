class Solution:
    def findMin(self, nums):
        start, end = 0, len(nums) - 1
        ans = nums[0]

        while start <= end:
            mid = start + (end - start) // 2
            # left side sorted
            if nums[mid] >= nums[0]:
                start = mid + 1
            else:
                ans = nums[mid]
                end = mid - 1
                
        return ans
