func singleNumber(arr []int) int {
      result := 0
    for _, num := range arr {
        result ^= num // XOR all elements
    }
    return result
}