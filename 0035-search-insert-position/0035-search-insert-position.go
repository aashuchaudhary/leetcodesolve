func searchInsert(nums []int, target int) int {
    start,end:=0,len(nums)-1
    ans:=len(nums)

    for start<=end{

        mid := start + (end-start) / 2
     if nums[mid] == target {
            ans = mid
            break
        } else if nums[mid] < target {
            start = mid + 1
        } else {
            ans = mid
            end = mid - 1
        }
    }
    return ans
}