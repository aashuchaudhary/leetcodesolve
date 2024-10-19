class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         // Sort by custom comparator (sort by distance to x, then by value)
        sort(arr.begin(), arr.end(), [x](int a, int b) {
            if (abs(a - x) == abs(b - x)) {
                return a < b;  // If distances are equal, smaller element first
            }
            return abs(a - x) < abs(b - x);  // Sort by distance
        });
        
        // Take the first k elements
        vector<int> result(arr.begin(), arr.begin() + k);
        
        // Sort the result to return in ascending order
        sort(result.begin(), result.end());
        
        return result;
    }
};