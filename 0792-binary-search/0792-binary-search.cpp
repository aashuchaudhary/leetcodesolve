class Solution {
public:
    int search(vector<int>& arr, int key) {
        int n=arr.size();
int start = 0, end = n - 1, mid;

    while (start <= end)
    {
        // mid ko fianl karo
        mid = start + (end-start)/2;
        if (arr[mid] == key)
            return mid;
        // arr[mid]<key
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
   
    }
};