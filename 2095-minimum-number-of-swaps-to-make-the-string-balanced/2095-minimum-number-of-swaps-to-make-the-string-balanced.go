package main

import "fmt"

func minSwaps(s string) int {
    size := 0

    // Iterate over the string characters
    for _, ch := range s {
        if ch == '[' {
            size++
        } else if size > 0 {
            size--
        }
    }

    // Return the number of swaps needed
    return (size + 1) / 2
}