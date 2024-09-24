func longestCommonPrefix(arr1 []int, arr2 []int) int {
    prefixMap := make(map[string]int)
    
    // Step 1: Build the prefix map for arr1
    for _, num := range arr1 {
        strNum := strconv.Itoa(num)
        prefix := ""
        for _, ch := range strNum {
            prefix += string(ch)
            prefixMap[prefix]++
        }
    }
    
    maxLength := 0
    
    // Step 2: Check for common prefixes in arr2
    for _, num := range arr2 {
        strNum := strconv.Itoa(num)
        prefix := ""
        for _, ch := range strNum {
            prefix += string(ch)
            if _, found := prefixMap[prefix]; found {
                if len(prefix) > maxLength {
                    maxLength = len(prefix)
                }
            }
        }
    }
    
    return maxLength
}