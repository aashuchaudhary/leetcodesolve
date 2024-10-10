class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int maxDist = 0;
        
        // Two pointers to traverse both arrays
        while (i < nums1.size() && j < nums2.size()) {
            // Check if the pair (i, j) is valid
            if (nums1[i] <= nums2[j]) {
                // Calculate the distance and update the maximum distance
                maxDist = max(maxDist, j - i);
                // Move j to the right to find a larger valid distance
                j++;
            } else {
                // If the pair is not valid, move i to the right
                i++;
            }
        }
        
        return maxDist;
    }
};