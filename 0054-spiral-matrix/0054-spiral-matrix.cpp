class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size(), col= matrix[0].size();
        int top= 0, bottom = row-1, left= 0, right= col-1;
        while(left<=right && top<=bottom)
        {

            // for top
            for(int j=left;j<=right;j++)
            // cout<<matrix[top][j];
            ans.push_back(matrix[top][j]);
            top++;
            // for right 
            for(int i= top; i<= bottom;i++)
            // cout<<matrix[i][right];
            ans.push_back(matrix[i][right]);

            right--;
            // for bottom
            if(top<=bottom)
            {
                for(int j=right;j>=left;j--)
                // cout<<matrix[bottom][j];
                ans.push_back(matrix[bottom][j]);

                bottom--;
            }
            // for left
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                // cout<<matrix[i][left];
                 ans.push_back(matrix[i][left]);

                left++;
            }
        }
        return ans;
    }
};