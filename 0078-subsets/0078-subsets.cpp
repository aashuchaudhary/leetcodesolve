class Solution {
public:
    
    void subsequence(vector<int>& arr, int index,int n,vector<vector<int > > &ans, vector<int> temp)
{
    // Base Case
    if (index == n)
    {
        ans.push_back(temp);
        return;
    }
    // Not include
    subsequence(arr, index + 1, n, ans, temp);
    // yes include
    temp.push_back(arr[index]);
    subsequence(arr, index + 1, n, ans, temp);
    temp.pop_back();
   
}
    
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int> > ans;
    vector<int> temp;
    subsequence(nums, 0, nums.size(), ans, temp);
     return ans;
    }
};
