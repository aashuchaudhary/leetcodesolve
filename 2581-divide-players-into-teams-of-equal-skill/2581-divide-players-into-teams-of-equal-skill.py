import collections

class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        available = collections.defaultdict(int)
        s = sum(skill) // (len(skill) // 2)
        chemistry = 0

        for x in skill:
            if available[s - x] > 0:
                chemistry += x * (s - x)
                available [s - x] -= 1
            else :
                available[x] += 1
        if any(available[x] > 0 for x in available.keys()):
            return -1
        return chemistry