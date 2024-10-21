class Solution {
public:
    int findMidStart(int left, int n, vector<int> &prefixSum, int target) {
        int lo = left + 1, hi = n - 2, mid, ans = -1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (prefixSum[mid] - prefixSum[left] >= target) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
    int findMidEnd(int left, int n, vector<int> &prefixSum, int target) {
        int lo = left + 1, hi = n - 2, mid, ans = -1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (prefixSum[mid] - prefixSum[left] <= target) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
    int waysToSplit(vector<int>& nums) {
        int n = nums.size(), leftSum, remainingSum, midStart, midEnd, ans = 0, mod = 1e9 + 7;
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        for (int left = 0; left < n - 2; left++) {
            leftSum = prefixSum[left];
            if (leftSum * 3 > prefixSum[n - 1]) {
                break;
            }
            remainingSum = prefixSum[n - 1] - prefixSum[left];
            midStart = findMidStart(left, n, prefixSum, leftSum);
            midEnd = findMidEnd(left, n, prefixSum, remainingSum / 2);
            if (midStart == -1 || midEnd == -1)
                break;
            ans = (ans + midEnd - midStart + 1) % mod;
        }
        return ans % mod;
    }
};