package main

import "fmt"

func rearrangeArray(nums []int) []int {
    n := len(nums)
    result := make([]int, n)
    posIndex, negIndex := 0, 1

    // Traverse the array and place positive and negative numbers
    for _, num := range nums {
        if num > 0 {
            result[posIndex] = num
            posIndex += 2  // Place positive numbers at even indices
        } else {
            result[negIndex] = num
            negIndex += 2  // Place negative numbers at odd indices
        }
    }
    return result
}