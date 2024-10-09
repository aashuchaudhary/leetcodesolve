package main

import "fmt"

func minAddToMakeValid(s string) int {
    open, close := 0, 0

    for _, ch := range s {
        if ch == '(' {
            // Increment for an opening parenthesis
            open++
        } else {
            // If there's an unmatched opening parenthesis, close it
            if open > 0 {
                open--
            } else {
                // Else we need a closing parenthesis to balance
                close++
            }
        }
    }

    // The result is the sum of unmatched open and close parentheses
    return open + close
}