class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # Set the start and end boundaries for binary search
        start, end = 1, max(piles)
        
        # Binary search to find the minimum eating speed
        while start <= end:
            mid = (start + end) // 2  # Calculate mid safely
            
            # Calculate total time required to eat all bananas at speed 'mid'
            total_time = 0
            for pile in piles:
                total_time += (pile + mid - 1) // mid  # Ceiling division
            
            # If total time exceeds the allowed hours, increase the speed
            if total_time > h:
                start = mid + 1
            else:
                end = mid - 1
        
        return start
