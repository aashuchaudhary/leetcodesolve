func mySqrt(x int) int {
    if x < 2 {
        return x
    }

    start, end, ans := 0, x, 0

    for start <= end {
        mid := start + (end - start) / 2

        if mid == x / mid {
            return mid
        } else if mid < x / mid {
            ans = mid
            start = mid + 1
        } else {
            end = mid - 1
        }
    }

    return ans
}
