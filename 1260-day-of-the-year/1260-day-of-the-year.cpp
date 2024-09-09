class Solution {
public:
     int dayOfYear(string date) {
        // Days in each month (index 0 is ignored for convenience)
        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Extract year, month, and day from the string
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        // Check if it's a leap year
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap && month > 2) {
            day++;  // Add 1 day if the date is after February in a leap year
        }
        
        // Calculate the day number
        for (int i = 0; i < month - 1; ++i) {
            day += daysInMonth[i];
        }
        
        return day;
    }
};