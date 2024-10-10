class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        
        // push element in decreasing order including elements of nums
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }
        
        int maxWidth = 0;
        
        // Step 2: Traverse from the end and find maximum width ramp
        for (int j = n - 1; j >= 0; --j) {  //itertae from right to left
            while (!s.empty() && nums[s.top()] <= nums[j]) {  //check stack is not empyu
                maxWidth = max(maxWidth, j - s.top());
                s.pop();
            }
        }
        
        return maxWidth;
    }
};


// NOTE: width of such a ramp is index: (j - i).
// nums is a random pair (i, j) for which i < j 
// and    nums[i] <= nums[j]

// eg; nums = [6,0,8,2,1,5]
// index   :   0,1,2,3,4,5
//  here the max width isin case of the  index 6-1,here we xheck the pair of elements in which we select the random element i and search for the the larget elemnt than the element present in the ith position and the the max other than i named as j and the the ax width will be (j-1).