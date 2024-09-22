class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
        {
        int n = arr.size()-1;
        int start=0,end =n;
        while(start<=end){
            int mid = end+(start-end)/2;
            // Peak element
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            return mid;
            // Right side move
            else if (arr[mid]>arr[mid-1])
           start=mid+1;
           // Left side move
            else
            end=mid-1;

        }
        return -1;
        }
};