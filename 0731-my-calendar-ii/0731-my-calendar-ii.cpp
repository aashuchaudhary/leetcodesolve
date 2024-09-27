class MyCalendarTwo {
public:
    map<int,int>bookings;
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        bookings[start]++;
        bookings[end]--;
        int activeBookings = 0;
        for(const auto& [time,count] : bookings){
            activeBookings += count;
            if(activeBookings >= 3){
                bookings[start]--;
                bookings[end]++;
                return false;
            }
        }
        return true;
    }
};