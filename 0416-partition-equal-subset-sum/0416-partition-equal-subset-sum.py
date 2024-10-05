class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2:
            return False

        dp=set()
        dp.add(0)

        target = sum(nums) // 2

        for i in range(len(nums) -1, -1,-1):
            nextDP = set()
            for T in dp:
                if (T + nums[i]) == target:
                    return True
                nextDP.add(T + nums[i])
                nextDP.add(T)
            dp = nextDP
        return True if target in dp else False