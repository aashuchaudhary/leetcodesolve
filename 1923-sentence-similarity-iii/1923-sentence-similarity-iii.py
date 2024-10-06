class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        # Split sentences into words
        s1 = sentence1.split(" ")
        s2 = sentence2.split(" ")

        # Ensure s1 is always the longer one (or they are equal)
        if len(s2) < len(s1):
            s1, s2 = s2, s1  # Swap to make s1 the longer one

        # Two pointer approach: match prefixes and suffixes
        l1, l2 = 0, 0  # Start of both lists

        # Find the longest matching prefix of both sentences
        while l1 < len(s1) and l2 < len(s2) and s1[l1] == s2[l2]:
            l1, l2 = l1 + 1, l2 + 1

        # Right pointers for matching suffix
        r1, r2 = len(s1) - 1, len(s2) - 1  # Initialize correctly

        # Find the longest matching suffix of both sentences
        while r1 >= 0 and r2 >= 0 and s1[r1] == s2[r2]:
            r1, r2 = r1 - 1, r2 - 1

        # If the left and right pointers have crossed, it's a match
        return l1 > r1
