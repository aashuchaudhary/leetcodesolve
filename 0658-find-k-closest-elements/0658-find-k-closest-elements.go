func findClosestElements(arr []int, k int, x int) []int {
	left, right := 0, len(arr)-1

	// Perform binary search
	for left < right {
		mid := left + (right-left)/2
		if arr[mid] < x {
			left = mid + 1
		} else {
			right = mid
		}
	}

	// Set left to the position where the closest element could be
	right = left
	left = right - 1

	// Collect k closest elements
	for i := 0; i < k; i++ {
		if left < 0 {
			right++
		} else if right >= len(arr) {
			left--
		} else if abs(arr[left]-x) <= abs(arr[right]-x) {
			left--
		} else {
			right++
		}
	}

	return arr[left+1 : right]
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}
