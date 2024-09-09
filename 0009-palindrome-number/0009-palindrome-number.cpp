class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        return false;

        int rem,ans=0,num = x;

        while(num){
            rem = num % 10;
            num /= 10;

            if(ans< INT_MIN/10 || ans>INT_MAX/10)
            return false;
            ans = ans *10 + rem;

        };
        if(x == ans)
        return true;
        else
        return false;
    }
};