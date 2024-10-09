class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()); // Sort the positions
        
        int left = 1; // Minimum possible force
        int right = position.back() - position.front(); // Maximum possible force
        int result = 0;
        
        // Binary search on the answer
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlaceBalls(position, m, mid)) { // Check if we can place the balls with this force
                result = mid; // Valid placement found
                left = mid + 1; // Try for a bigger force
            } else {
                right = mid - 1; // Try a smaller force
            }
        }
        
        return result; // Return the best valid result found
    }
    
    bool canPlaceBalls(const vector<int>& position, int m, int minForce) {
        int count = 1; // Place the first ball
        int lastPosition = position[0]; // Position of the last placed ball
        
        for (int i = 1; i < position.size(); i++) {
            // Check if we can place a ball in this basket
            if (position[i] - lastPosition >= minForce) {
                count++; // Place the ball
                lastPosition = position[i]; // Update last position
                if (count == m) return true; // All balls placed
            }
        }
        
        return false; // Not possible to place all balls
    }
};
