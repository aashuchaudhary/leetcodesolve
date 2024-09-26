class MyCalendar:

    def __init__(self):
        self.bookings = []  # Stores booked intervals

    def book(self, start: int, end: int) -> bool:
        for s, e in self.bookings:
            # Check for overlap
            if max(start, s) < min(end, e):
                return False
        # Add the interval if no overlap is found
        self.bookings.append((start, end))
        return True
