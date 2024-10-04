import collections

class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()  # Sort to easily pair players
        n = len(skill)
        
        group_count = n // 2
        total_skill = sum(skill)
        
        # Ensure total skill is divisible by group count
        if total_skill % group_count != 0:
            return -1
        
        target_sum = total_skill // group_count  # Target sum for each pair
        q = collections.deque(skill)
        chemistry = 0

        for i in range(n//2):
            a = skill[i]  # Smallest element
            b = skill[n - i -1]      # Largest element

            if a + b != target_sum:  # Check if the pair matches the target sum
                return -1
            
            chemistry += a * b  # Accumulate the chemistry of the pair

        return chemistry
