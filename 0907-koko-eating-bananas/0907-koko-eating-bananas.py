class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        start, end = 1, max(piles)
        

        
        while start <= end:
            mid = (start + end) // 2 

            total_time = 0
            for pile in piles:
                total_time += (pile + mid - 1) // mid  

            # If total time exceeds the allowed hours, increase the speed
            if total_time > h:
                start = mid + 1
            else:
                end = mid - 1
        
        return start