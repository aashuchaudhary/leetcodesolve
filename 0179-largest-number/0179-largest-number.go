func largestNumber(nums []int) string {
    // Convert integers to strings
	array := make([]string, len(nums))
	for i, num := range nums {
		array[i] = strconv.Itoa(num)
	}

	// Custom sorting with a comparator function
	sort.Slice(array, func(i, j int) bool {
		// Compare the concatenation of two strings in both possible orders
		return array[j]+array[i] < array[i]+array[j]
	})

	// Handle the case where the largest number is "0"
	if array[0] == "0" {
		return "0"
	}

	// Build the largest number from the sorted array
	return strings.Join(array, "")
}