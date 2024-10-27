func increasingTriplet(nums []int) bool {
    if len(nums) < 3 {
        return false
    }

    left, mid := int(^uint(0) >> 1), int(^uint(0) >> 1) // Set to max int value

    for _, num := range nums {
        if num > mid {
            return true
        } else if num < left {
            left = num
        } else if num > left && num < mid {
            mid = num
        }
    }

    return false
}
