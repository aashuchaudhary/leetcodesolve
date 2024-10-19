class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
             // Find the position of the closest element to x using binary search
        int n = arr.size();
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // Initialize two pointers
        int start = left - 1; // pointer to the left of the closest position
        int end = left;       // pointer to the closest position

        // Collect k closest elements
        vector<int> result;

        while (k--) {
            // If we've exhausted one side, we need to take from the other
            if (start < 0) {
                result.push_back(arr[end++]);
            } else if (end >= n) {
                result.push_back(arr[start--]);
            } else if (abs(arr[start] - x) <= abs(arr[end] - x)) {
                result.push_back(arr[start--]);
            } else {
                result.push_back(arr[end++]);
            }
        }

        // Sort the result before returning
        sort(result.begin(), result.end());
        return result;
    }
};