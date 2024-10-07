class Solution {
public:
    int minLength(string s) {
        stack<char> stack;

        // Traverse the input string
        for (int i = 0; i < s.length(); i++) {
            char cur_char = s[i];

            // If stack is empty, just push the current character
            if (stack.empty()) {
                stack.push(cur_char);
                continue;
            }

            // Check if the top of the stack forms "AB" or "CD" with cur_char
            if (cur_char == 'B' && stack.top() == 'A') {
                stack.pop(); // Remove the "AB" pair
            }
            else if (cur_char == 'D' && stack.top() == 'C') {
                stack.pop(); // Remove the "CD" pair
            }
            else {
                stack.push(cur_char); // Push the current character if no pair is formed
            }
        }

        // Return the remaining size of the stack
        return stack.size();
    }
};
