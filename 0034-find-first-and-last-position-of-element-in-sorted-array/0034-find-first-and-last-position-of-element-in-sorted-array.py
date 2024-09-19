class Solution:
    def searchRange(self, nums, target):
        start, end = 0, len(nums) - 1
        first, last = -1, -1
        
        # Find the first occurrence
        while start <= end:
            mid = start + (end - start) // 2
            if nums[mid] == target:
                first = mid
                end = mid - 1
            elif nums[mid] < target:
                start = mid + 1
            else:
                end = mid - 1
        
        # Find the last occurrence
        start, end = 0, len(nums) - 1
        while start <= end:
            mid = start + (end - start) // 2
            if nums[mid] == target:
                last = mid
                start = mid + 1
            elif nums[mid] < target:
                start = mid + 1
            else:
                end = mid - 1
        
        # Create the result list
        return [first, last]