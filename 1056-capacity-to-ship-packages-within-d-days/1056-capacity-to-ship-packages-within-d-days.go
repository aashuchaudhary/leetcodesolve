func shipWithinDays(weights []int, days int) int {
    start,end:=0,0
    n:=len(weights)

    for i := 0 ; i<n ; i++ { 
        start = int(math.Max(float64(start),float64(weights[i])))
        end += weights[i]
    }
    ans:=-1

    // Binary search 

    for start <= end {
        mid:= start + (end-start)/2
        currentweights := 0
        requireddays := 1
        // Allocation of weights to days

        for  i := 0; i < n ; i++ {
            currentweights += weights[i]

            // if weigts exceed mid,allocate to the next days
            if currentweights > mid {
                requireddays++
                currentweights = weights[i]
            }
        }

        // If require days are <= given days ,update and and search left pat
        if requireddays <= days {
            ans = mid
            end = mid - 1
        }else {

        start = mid + 1
        }

    }
    return ans
}