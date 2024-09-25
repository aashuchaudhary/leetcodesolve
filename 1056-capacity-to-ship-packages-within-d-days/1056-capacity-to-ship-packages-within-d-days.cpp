class Solution 
{
public:
// Function to find the least weight capacity of the ship
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int start = 0 ,end=0,ans=-1,mid;
        int n=weights.size();

        for (int i = 0; i< n; i++)
        {
            start= max(start,weights[i]);
            end += weights[i];
        }

        while(start<=end)
        {
            mid = start + (end - start )/2;
            int currentweight = 0,requireddays=1;
            // Allocation of weights to days 
            for(int i = 0; i < n; i++)
            {
                currentweight += weights[i];

                // If curent weights exceed mid,allocate to the next day
                if (currentweight > mid)
                {
                    requireddays++;
                    currentweight=weights[i];
                }
            }

            // If required days are <= given days ,then update and and search left
            if(requireddays <= days)
            {
                ans = mid;
                end = mid - 1;

            }else
            start = mid + 1;
        }
        return ans;
    }
};