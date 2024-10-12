class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;

        // Record start and end events
        for (const auto& interval : intervals) {
            events.push_back({interval[0], 1});      // +1 for starting the interval
            events.push_back({interval[1] + 1, -1}); // -1 for ending the interval
        }

        // Sort events by time. If times are equal, process starting events before ending events.
        sort(events.begin(), events.end());

        int maxGroups = 0, currentGroups = 0;

        // Sweep through the sorted events
        for (const auto& event : events) {
            currentGroups += event.second;  // Update current group count
            maxGroups = max(maxGroups, currentGroups);  // Track the maximum
        }

        return maxGroups;
    }
};