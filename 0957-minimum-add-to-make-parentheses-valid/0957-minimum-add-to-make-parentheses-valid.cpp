class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                // Increment for an opening parenthesis
                open++;
            } else {
                // If there's an unmatched opening parenthesis, close it
                if (open > 0) {
                    open--;
                } else {
                    // Else we need a closing parenthesis to balance
                    close++;
                }
            }
        }
        
        // The result is the sum of unmatched open and close parentheses
        return open + close;
    }
};
