func uncommonFromSentences(s1 string, s2 string) []string {
    // Combine both sentences
	s := s1 + " " + s2

	// Create a map to store word counts
	wordCount := make(map[string]int)

	// Split the combined string by spaces into words
	words := strings.Fields(s)

	// Count occurrences of each word
	for _, word := range words {
		wordCount[word]++
	}

	// List to store uncommon words (words with count == 1)
	var ans []string
	for word, count := range wordCount {
		if count == 1 {
			ans = append(ans, word)
		}
	}

	return ans
}