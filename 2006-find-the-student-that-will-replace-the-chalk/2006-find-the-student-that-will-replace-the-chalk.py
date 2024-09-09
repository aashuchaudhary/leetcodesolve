class Solution:
    def chalkReplacer(self, chalk, k):
        # Calculate the total sum of chalk required in one complete round
        total_sum = sum(chalk)
        
        # Calculate the remaining chalk after full rounds
        rem = k % total_sum
        
        # Find the student who will replace the chalk
        for i in range(len(chalk)):
            rem -= chalk[i]
            if rem < 0:
                return i
