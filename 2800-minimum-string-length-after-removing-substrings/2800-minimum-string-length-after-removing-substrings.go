package main

import (
	"fmt"
)

func minLength(s string) int {
	// Initialize a stack as a slice of runes
	stack := []rune{}

	// Traverse the string `s`
	for _, c := range s {
		// Check if the stack is not empty and matches the pattern "AB" or "CD"
		if len(stack) > 0 {
			top := stack[len(stack)-1]
			if top == 'A' && c == 'B' {
				// Pop 'A' when "AB" is found
				stack = stack[:len(stack)-1]
				continue
			} else if top == 'C' && c == 'D' {
				// Pop 'C' when "CD" is found
				stack = stack[:len(stack)-1]
				continue
			}
		}
		// Otherwise, push the current character onto the stack
		stack = append(stack, c)
	}

	// Return the size of the remaining stack
	return len(stack)
}