class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> maxHeap(nums.begin(), nums.end());

        long long score = 0;
        for (int i = 0; i < k; i++) {
            long long maxVal = maxHeap.top();
            maxHeap.pop();
            score += maxVal;
            maxHeap.push(ceil(maxVal / 3.0));
        }

        return score;
    }
};