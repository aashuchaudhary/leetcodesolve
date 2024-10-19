class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        # Base case: the first binary string
        if n == 1:
            return "0"
        
        # Length of Sn
        length = (1 << n) - 1  # This is 2^n - 1
        mid = length // 2 + 1   # Middle index is at (length // 2) + 1
        
        if k == mid:
            return "1"  # Middle element is always 1
        elif k < mid:
            # If k is in the first half, simply look in Sn-1
            return self.findKthBit(n - 1, k)
        else:
            # If k is in the second half
            # Calculate the mirrored position in Sn-1
            mirrored_index = length - k + 1
            # Get the bit from Sn-1 and invert it
            return "0" if self.findKthBit(n - 1, mirrored_index) == "1" else "1"