/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
package main

import (
	"fmt"
	"math"
)

func canMerge(trees []*TreeNode) *TreeNode {
	children := make(map[int]bool)
	treeMap := make(map[int]*TreeNode)

	// Step 1: Populate the children map and tree map
	for _, t := range trees {
		treeMap[t.Val] = t
		if t.Left != nil {
			children[t.Left.Val] = true
		}
		if t.Right != nil {
			children[t.Right.Val] = true
		}
	}

	// Step 2: Find the root, which is not in the children set
	var root *TreeNode
	for _, t := range trees {
		if !children[t.Val] {
			if root != nil {
				return nil // More than one root found
			}
			root = t
		}
	}
	if root == nil {
		return nil // No root found
	}

	unseen := make(map[int]bool)
	for _, t := range trees {
		unseen[t.Val] = true
	}

	// Helper function to check if the tree is a valid BST
	var checkBST func(node *TreeNode, lo, hi float64) bool
	checkBST = func(node *TreeNode, lo, hi float64) bool {
		if node == nil {
			return true
		}

		if float64(node.Val) <= lo || float64(node.Val) >= hi {
			return false
		}

		// Remove the current node from the unseen set
		delete(unseen, node.Val)

		// If the node can be replaced with a tree, do so
		if replacement, exists := treeMap[node.Val]; exists {
			node = replacement
		}

		// Recursively check left and right subtrees
		return checkBST(node.Left, lo, float64(node.Val)) && checkBST(node.Right, float64(node.Val), hi)
	}

	// Step 3: Validate if the constructed tree is a valid BST
	if !checkBST(root, -math.MaxFloat64, math.MaxFloat64) {
		return nil
	}

	// Check if there are any nodes left in the unseen set
	if len(unseen) > 0 {
		return nil
	}

	// Helper function to build the final BST by replacing nodes
	var buildBST func(node *TreeNode) *TreeNode
	buildBST = func(node *TreeNode) *TreeNode {
		if node == nil {
			return nil
		}

		if replacement, exists := treeMap[node.Val]; exists {
			node = replacement
			node.Left = buildBST(node.Left)
			node.Right = buildBST(node.Right)
		}

		return node
	}

	// Step 4: Build the final merged BST
	return buildBST(root)
}