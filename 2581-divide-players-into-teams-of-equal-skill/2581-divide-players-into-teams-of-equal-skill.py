import collections

class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        available = collections.defaultdict(int)
        s = sum(skill) // (len(skill) // 2)  # Target sum for each pair
        chemistry = 0

        for x in skill:
            if available[s - x] > 0:  # Check if complement exists
                chemistry += x * (s - x)  # Add product to chemistry
                available[s - x] -= 1  # Decrement count of complement
            else:
                available[x] += 1  # Store current element for pairing

        # If any element remains unpaired, return -1
        if any(available[x] > 0 for x in available.keys()):
            return -1
        
        return chemistry
