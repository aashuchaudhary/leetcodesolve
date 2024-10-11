class Solution:
    def rearrangeArray(self, nums):
        n = len(nums)
        result = [0] * n
        posIndex, negIndex = 0, 1

        # Traverse the array and place positive and negative numbers
        for num in nums:
            if num > 0:
                result[posIndex] = num
                posIndex += 2  # Place positive numbers at even indices
            else:
                result[negIndex] = num
                negIndex += 2  # Place negative numbers at odd indices

        return result