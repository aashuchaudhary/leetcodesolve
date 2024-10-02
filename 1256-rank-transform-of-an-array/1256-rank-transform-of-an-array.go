package main

import (
	"fmt"
	"sort"
)

type int2 struct {
	val, idx int
}

func arrayRankTransform(arr []int) []int {
	n := len(arr)
	arrIdx := make([]int2, n)
	for i, x := range arr {
		arrIdx[i] = int2{val: x, idx: i}
	}
	
	sort.Slice(arrIdx, func(i, j int) bool {
		return arrIdx[i].val < arrIdx[j].val
	})
	
	ans := make([]int, n)
	prev := int(-1 << 31) // equivalent to INT_MIN
	curr := 0
	
	for _, p := range arrIdx {
		if p.val > prev {
			curr++
		}
		ans[p.idx] = curr
		prev = p.val
	}
	
	return ans
}