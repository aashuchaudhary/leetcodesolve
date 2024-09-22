func search(arr []int, target int) int {
    start, end := 0, len(arr)-1
    
    for start <= end {
        mid := start + (end-start)/2
        
        // Element found
        if arr[mid] == target {
            return mid
        }
        
        // Left side is sorted
        if arr[mid] >= arr[0] {
            if arr[start] <= target && target <= arr[mid] {
                end = mid - 1
            } else {
                start = mid + 1
            }
        } else { 
            // Right side is sorted
            if arr[mid] <= target && target <= arr[end] {
                start = mid + 1
            } else {
                end = mid - 1
            }
        }
    }
    
    return -1
}