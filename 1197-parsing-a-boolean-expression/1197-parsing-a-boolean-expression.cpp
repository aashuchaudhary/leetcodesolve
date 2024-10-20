class Solution {
    void evaluate(std::stack<char>& optr, std::stack<char>& operand) {
        char op = optr.top();  // Get the character at the top
        optr.pop();  // Remove the operator from the stack
        bool ans;

        if (op == '|') {
            ans = false;  // For OR, initial value should be false
            while (operand.top() != '(') {
                ans |= (operand.top() == 't');
                operand.pop();
            }
            operand.pop();  // Pop the '('
        } else if (op == '&') {
            ans = true;  // For AND, initial value should be true
            while (operand.top() != '(') {
                ans &= (operand.top() == 't');
                operand.pop();
            }
            operand.pop();  // Pop the '('
        } else if (op == '!') {
            ans = (operand.top() == 't');
            ans = !ans;  // Negate the value
            operand.pop();  // Pop the value
            operand.pop();  // Pop the '('
        }

        if (ans) operand.push('t');  // Push true result back to operand stack
        else operand.push('f');  // Push false result back to operand stack
    }

public:
    bool parseBoolExpr(std::string expression) {
        std::stack<char> optr, operand;
        int idx = 0;

        while (expression[idx]) {
            if (expression[idx] == '!' || expression[idx] == '&' || expression[idx] == '|') {
                optr.push(expression[idx]);
            } else if (expression[idx] == 't' || expression[idx] == 'f') {
                operand.push(expression[idx]);  // Push operand
            } else if (expression[idx] == '(') {
                operand.push(expression[idx]);  // Pushing opening parenthesis
            } else if (expression[idx] == ')') {
                evaluate(optr, operand);  // Evaluate when closing parenthesis is encountered
            }
            idx++;
        }

        return operand.top() == 't';  // Final result check
    }
};
