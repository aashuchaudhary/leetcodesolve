class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());  // Sort to facilitate pairing
        int n = skill.size();
        if (n % 2 != 0) return -1;  // Ensure even number of players
        
        deque<int> q(skill.begin(), skill.end());  // Use deque for efficient popping
        long long total_skill = accumulate(skill.begin(), skill.end(), 0LL);  // Total sum of skills (use long long)
        int group_count = n / 2;  // Number of groups
        
        // Target sum for each group of two players
        if (total_skill % group_count != 0) return -1;
        int target_sum = total_skill / group_count;
        
        long long chemistry = 0;  // Use long long for chemistry
        while (!q.empty()) {
            int a = q.front();  // Smallest element
            q.pop_front();
            if (q.empty()) return -1;  // Ensure there's another element to pair with
            
            int b = q.back();   // Largest element
            q.pop_back();
            
            if (a + b != target_sum) return -1;  // Check if the sum of the pair is valid
            chemistry += 1LL * a * b;  // Accumulate chemistry, ensure long long multiplication
        }

        return chemistry;
    }
};