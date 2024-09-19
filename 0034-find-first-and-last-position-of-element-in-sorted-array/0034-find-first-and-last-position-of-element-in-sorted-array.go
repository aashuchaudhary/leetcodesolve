func searchRange(nums []int, target int) []int {
	start, end := 0, len(nums)-1
	first, last := -1, -1

	// Find the first occurrence
	for start <= end {
		mid := start + (end-start)/2
		if nums[mid] == target {
			first = mid
			end = mid - 1 // Continue searching in the left half
		} else if nums[mid] < target {
			start = mid + 1
		} else {
			end = mid - 1
		}
	}

	// Find the last occurrence
	start, end = 0, len(nums)-1
	for start <= end {
		mid := start + (end-start)/2
		if nums[mid] == target {
			last = mid
			start = mid + 1 // Continue searching in the right half
		} else if nums[mid] < target {
			start = mid + 1
		} else {
			end = mid - 1
		}
	}

	// Create and return the result slice
	return []int{first, last}
}