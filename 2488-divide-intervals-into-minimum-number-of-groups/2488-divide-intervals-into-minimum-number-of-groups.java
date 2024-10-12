import java.util.*;

class Solution {
    public int minGroups(int[][] intervals) {
        List<int[]> events = new ArrayList<>();

        // Record start and end events
        for (int[] interval : intervals) {
            events.add(new int[]{interval[0], 1});     // +1 for starting the interval
            events.add(new int[]{interval[1] + 1, -1}); // -1 for ending the interval
        }

        // Sort events by time. If times are equal, process starting events before ending events.
        events.sort((a, b) -> {
            if (a[0] == b[0]) {
                return a[1] - b[1]; // Process starts before ends when times are equal
            }
            return a[0] - b[0]; // Otherwise sort by time
        });

        int maxGroups = 0, currentGroups = 0;

        // Sweep through the sorted events
        for (int[] event : events) {
            currentGroups += event[1];  // Update current group count
            maxGroups = Math.max(maxGroups, currentGroups);  // Track the maximum number of groups
        }

        return maxGroups;
    }
}