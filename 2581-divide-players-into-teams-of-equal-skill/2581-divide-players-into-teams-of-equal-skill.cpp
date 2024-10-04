class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int, int> available;  // To store counts of each element
        int n = skill.size();
        if (n % 2 != 0) return -1;  // Ensure even number of players
        
        long long total_skill = accumulate(skill.begin(), skill.end(), 0LL);  // Sum of all skill levels (use long long)
        int group_count = n / 2;  // Number of groups
        
        // Calculate target sum for each pair
        if (total_skill % group_count != 0) return -1;
        int target_sum = total_skill / group_count;
        
        long long chemistry = 0;  // Use long long for chemistry
        for (int x : skill) {
            if (available[target_sum - x] > 0) {
                chemistry += 1LL * x * (target_sum - x);  // Accumulate chemistry, ensure long long multiplication
                available[target_sum - x]--;  // Decrement complement count
            } else {
                available[x]++;  // Store current element count
            }
        }
        
        // If any element remains unpaired, return -1
        for (auto& pair : available) {
            if (pair.second > 0) return -1;
        }

        return chemistry;
    }
};