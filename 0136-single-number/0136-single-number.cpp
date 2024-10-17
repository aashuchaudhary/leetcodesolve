class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int result = 0;
        for (int num : arr) {
            result ^= num;  // XOR all elements
        }
        return result;
    }
};