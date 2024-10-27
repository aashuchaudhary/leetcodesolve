class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False

        left, mid = float("inf"), float("inf")

        for num in nums:
            if num > mid:
                return True
            elif num < left:
                left = num
            elif left < num < mid:
                mid = num

        return False
