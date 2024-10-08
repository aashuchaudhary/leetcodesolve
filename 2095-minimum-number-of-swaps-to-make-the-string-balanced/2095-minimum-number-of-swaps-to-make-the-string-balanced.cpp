class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;

        for(char &ch : s){
            if(ch =='['){
                st.push(ch);
            }else if(!st.empty()) {
                st.pop();
            }
        }
        // size of stack  =  no of thhe open bRaackets
        return (st.size() + 1) / 2;
    }
};