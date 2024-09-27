class MyCalendarTwo:

    def __init__(self):
        self.bookings = {}  # Dictionary to store the start and end times

    def book(self, start: int, end: int) -> bool:
        if start not in self.bookings:
            self.bookings[start] = 0
        if end not in self.bookings:
            self.bookings[end] = 0

        # Increment count for start, decrement for end
        self.bookings[start] += 1
        self.bookings[end] -= 1

        activeBookings = 0
        for time in sorted(self.bookings):
            activeBookings += self.bookings[time]
            if activeBookings >= 3:
                # Revert the changes if triple booking is detected
                self.bookings[start] -= 1
                self.bookings[end] += 1
                return False

        return True