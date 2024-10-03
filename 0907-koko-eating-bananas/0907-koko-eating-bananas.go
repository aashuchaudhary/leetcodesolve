func minEatingSpeed(piles []int, h int) int {
    // Initialize start and end for binary search
    start, end := 1, 0
    n := len(piles)

    // Calculate end as the maximum number of bananas in any pile
    for i := 0; i < n; i++ {
        if piles[i] > end {
            end = piles[i]
        }
    }

    var ans int
    for start <= end {
        mid := start + (end - start) / 2
        totalTime := 0
        
        // Calculate the total time required at speed mid
        for i := 0; i < n; i++ {
            totalTime += (piles[i] + mid - 1) / mid // Equivalent to math.ceil(piles[i]/mid)
        }

        // Check if total time is within the allowed hours
        if totalTime <= h {
            ans = mid // mid is a valid speed
            end = mid - 1 // Try to find a smaller valid speed
        } else {
            start = mid + 1 // Increase speed if time exceeds h
        }
    }

    return ans
}
