func findClosestElements(arr []int, k int, x int) []int {
	left, right := 0, len(arr)-1

	// Binary search to find the closest element to x
	for right-left >= k {
		if abs(arr[left]-x) <= abs(arr[right]-x) {
			right-- // Remove the rightmost element
		} else {
			left++ // Remove the leftmost element
		}
	}

	return arr[left : left+k]
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}
