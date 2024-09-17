class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
         # Combine both sentences
        s = s1 + " " + s2

        # Dictionary to store the word counts
        word_count = defaultdict(int)

        # Temporary variable to store each word
        tmp = ""
        for val in s:  # Iterate through each character in the combined string
            if val == ' ':
                word_count[tmp] += 1
                tmp = ""
            else:
                tmp += val
        
        # If there's any word left in `tmp`, add it to the word count
        if tmp != "":
            word_count[tmp] += 1

        # List to store the uncommon words (words with count == 1)
        ans = [word for word, count in word_count.items() if count == 1]

        return ans