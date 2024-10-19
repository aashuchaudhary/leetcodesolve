class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
               // Create a max-heap to keep track of the k closest elements
        priority_queue<pair<int, int>> maxHeap;

        for (int num : arr) {
            // Calculate the distance from x
            int distance = abs(num - x);
            // Push the distance and number onto the heap
            maxHeap.push({distance, num});
            
            // If the heap size exceeds k, pop the farthest element
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Extract the k closest elements from the heap
        vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        // Sort the result before returning
        sort(result.begin(), result.end());
        return result;
    }
};