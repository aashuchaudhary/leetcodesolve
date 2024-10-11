class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int posIndex = 0, negIndex = 1;

        // Traverse the array and place positive and negative numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result[posIndex] = nums[i];
                posIndex += 2;  // Place positive numbers at even indices
            } else {
                result[negIndex] = nums[i];
                negIndex += 2;  // Place negative numbers at odd indices
            }
        }
        return result;
    }
};