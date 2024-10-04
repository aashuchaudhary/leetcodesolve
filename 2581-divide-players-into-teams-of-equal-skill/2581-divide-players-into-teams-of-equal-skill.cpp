class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());  // Sort the skill list
        int n = skill.size();
        if (n % 2 != 0) return -1;  // Ensure there is an even number of players
        
        long long total_skill = accumulate(skill.begin(), skill.end(), 0LL);  // Sum of all skills (use long long)
        int group_count = n / 2;  // Number of groups
        
        // If the total skill isn't divisible by group count, return -1
        if (total_skill % group_count != 0) return -1;
        
        int target_sum = total_skill / group_count;  // Target sum for each group
        long long chemistry = 0;  // Use long long for chemistry
        
        int i = 0, j = n - 1;
        while (i < j) {
            if (skill[i] + skill[j] != target_sum) return -1;  // Check if the sum of pairs is valid
            chemistry += 1LL * skill[i] * skill[j];  // Accumulate chemistry, ensure it's long long multiplication
            i++;
            j--;
        }
        
        return chemistry;
    }
};