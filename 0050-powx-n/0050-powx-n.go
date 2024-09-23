// Function to calculate x^n
func myPow(x float64, n int) float64 {
	if x == 0 {
		return 0
	}
	if n == 0 {
		return 1
	}

	// Handle negative exponent
	if n < 0 {
		x = 1 / x
		n = -n
	}

	// Recursive function to calculate power
	res := myPow(x, n/2)
	res *= res

	// If n is odd, multiply by x
	if n%2 != 0 {
		return res * x
	}
	return res
}