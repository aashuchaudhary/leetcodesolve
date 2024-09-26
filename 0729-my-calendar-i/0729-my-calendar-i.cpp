class MyCalendar {
public:
    vector<pair<int, int>> bookings; // Stores booked intervals

    MyCalendar() {}

    bool book(int start, int end) {
        for (auto& interval : bookings) {
            // Check if there's an overlap
            if (max(start, interval.first) < min(end, interval.second)) {
                return false;
            }
        }
        // Add the interval if no overlap is found
        bookings.push_back({start, end});
        return true;
    }
};