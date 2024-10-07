class Solution:
    def minLength(self, s: str) -> int:
        stack = [None]
        for c in s:
            # Check for "AB" and "CD" patterns
            if stack[-1] == 'A' and c == 'B':
                stack.pop()
            elif stack[-1] == 'C' and c == 'D':
                stack.pop()
            else:
                stack.append(c)
        return len(stack) - 1  # Subtract 1 to ignore the initial 'None' in stack
