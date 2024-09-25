class Solution:
    # Function to find the least weight capacity of the ship
    def shipWithinDays(self, weights, days):
        start = max(weights)
        end = sum(weights)
        ans = -1
        
        # Binary search to find the minimum capacity
        while start <= end:
            mid = start + (end - start) // 2
            currentweight = 0
            requireddays = 1
            
            # Allocation of weights to days
            for weight in weights:
                currentweight += weight
                
                # If current weight exceeds mid, allocate to the next day
                if currentweight > mid:
                    requireddays += 1
                    currentweight = weight  # Start with the current weight
                
            # If required days are <= given days, update ans and search left
            if requireddays <= days:
                ans = mid
                end = mid - 1
            else:
                start = mid + 1
        
        return ans
