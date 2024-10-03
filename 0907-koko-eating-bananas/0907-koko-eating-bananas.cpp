class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long start = 1, end = 0, ans, mid;  // Use long long for large ranges
        int n = piles.size();

        // Calculate the maximum pile value to set the upper limit (end)
        for (int i = 0; i < n; i++) {
            end = max(end, (long long)piles[i]);  // Convert to long long
        }

        // Binary search to find the minimum eating speed
        while (start <= end) {
            mid = start + (end - start) / 2;  // Calculate mid safely

            // Calculate the total time required to eat all piles at speed 'mid'
            long long total_time = 0;
            for (int i = 0; i < n; i++) {
                total_time += (piles[i] + mid - 1) / mid;  // Ceiling division
            }

            // If total time exceeds h, increase the speed
            if (total_time > h) {
                start = mid + 1;
            } else {
                ans = mid;  // Try to minimize speed
                end = mid - 1;
            }
        }

        return ans;
    }
};
