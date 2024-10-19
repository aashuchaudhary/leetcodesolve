class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
             int left = 0;
        int right = arr.size() - 1;
        
        // Reduce the range to exactly k elements
        while (right - left >= k) {
            // Compare distances of left and right to x
            if (abs(arr[left] - x) > abs(arr[right] - x)) {
                left++;  // Move left closer to the right
            } else {
                right--;  // Move right closer to the left
            }
        }
        
        // Return the k closest elements
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};