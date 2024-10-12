class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        events = []
        
        # Record start and end events
        for interval in intervals:
            start, end = interval
            events.append((start, 1))      # +1 for a start of an interval
            events.append((end + 1, -1))   # -1 for the end of an interval
        
        # Sort the events by time, process starts before ends if they are at the same time
        events.sort()

        max_groups = 0
        current_groups = 0
        
        # Sweep through events
        for event in events:
            current_groups += event[1]
            max_groups = max(max_groups, current_groups)
        
        return max_groups
