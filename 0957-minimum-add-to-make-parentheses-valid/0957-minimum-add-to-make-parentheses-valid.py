class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open_count = 0
        close_count = 0
        
        for ch in s:
            if ch == '(':
                # Increment for an opening parenthesis
                open_count += 1
            else:
                # If there's an unmatched opening parenthesis, close it
                if open_count > 0:
                    open_count -= 1
                else:
                    # Else we need a closing parenthesis to balance
                    close_count += 1

        # The result is the sum of unmatched open and close parentheses
        return open_count + close_count
