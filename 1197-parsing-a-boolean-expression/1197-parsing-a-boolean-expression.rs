use std::collections::VecDeque;

impl Solution {
    pub fn parse_bool_expr(expression: String) -> bool {
        let mut stk = VecDeque::new();  // Stack to hold characters and operators

        // Iterate over each character in the expression
        for c in expression.chars() {
            if c != ')' && c != ',' {
                stk.push_back(c);  // Push valid characters to the stack
            } else if c == ')' {  // When ')' is encountered, evaluate subexpression
                let mut exp = Vec::new();  // Vector to hold boolean values
                
                // Pop characters until '(' is found, collect 't' or 'f' values
                while let Some(&top) = stk.back() {
                    if top == '(' {
                        break;
                    }
                    stk.pop_back();
                    exp.push(top == 't');
                }
                
                stk.pop_back();  // Pop the '(' from the stack
                
                if let Some(&op) = stk.back() {
                    stk.pop_back();
                    let mut v = exp[0];  // Initialize result with the first value
                    
                    // Perform the corresponding logical operation
                    if op == '&' {  // AND operation
                        for &b in &exp {
                            v &= b;
                        }
                    } else if op == '|' {  // OR operation
                        for &b in &exp {
                            v |= b;
                        }
                    } else {  // NOT operation
                        v = !v;
                    }
                    
                    // Push the result back to the stack as 't' or 'f'
                    if v {
                        stk.push_back('t');
                    } else {
                        stk.push_back('f');
                    }
                }
            }
        }
        
        // Return the final result from the stack
        stk.back() == Some(&'t')
    }
}
