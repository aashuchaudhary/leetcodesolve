class Solution {
private:
    long long subarraymins(vector<int>& nums){
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            while (!s1.empty() && nums[s1.top()] >= nums[i]) {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }

        while (!s1.empty()) s1.pop();


        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && nums[s2.top()] > nums[i]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }


        for (int i = 0; i < n; i++) {
            sum += (long long)left[i] * right[i] * nums[i];
        }

        return sum;
    }

    long long subarraymaxs(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;
        long long sum = 0;


        for (int i = 0; i < n; i++) {
            while (!s1.empty() && nums[s1.top()] <= nums[i]) {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }


        while (!s1.empty()) s1.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && nums[s2.top()] < nums[i]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }


        for (int i = 0; i < n; i++) {
            sum += (long long)left[i] * right[i] * nums[i];
        }

        return sum;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        long long maxi = subarraymaxs(nums);
        long long mini = subarraymins(nums);
        return maxi - mini;
    }
};