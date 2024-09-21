func lexicalOrder(n int) []int {
       ans := make([]int, 0, n)

    var f func(i int)
    f = func(i int) {
        if i > n {
            return
        }
        if i > 0 {
            ans = append(ans, i)
        }
        for j := 0; j <= 9; j++ {
            if i == 0 && j == 0 {
                continue
            }
            x := 10*i + j
            if x > n {
                break
            }
            f(x)
        }
    }

    f(0)
    return ans
}