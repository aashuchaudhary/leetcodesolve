
func findClosestElements(arr []int, k int, x int) []int {
	distanceMap := make([]struct {
		Value    int
		Distance int
	}, len(arr))

	for i, num := range arr {
		distanceMap[i] = struct {
			Value    int
			Distance int
		}{Value: num, Distance: abs(num - x)}
	}

	// Sort by distance, and then by value if distances are equal
	sort.Slice(distanceMap, func(i, j int) bool {
		if distanceMap[i].Distance == distanceMap[j].Distance {
			return distanceMap[i].Value < distanceMap[j].Value
		}
		return distanceMap[i].Distance < distanceMap[j].Distance
	})

	// Collect the closest k elements
	result := make([]int, 0, k)
	for i := 0; i < k; i++ {
		result = append(result, distanceMap[i].Value)
	}

	sort.Ints(result) // Sort the result before returning
	return result
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}
