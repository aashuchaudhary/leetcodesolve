
type MyCalendar struct {
	bookings [][2]int // Stores booked intervals
}

func Constructor() MyCalendar {
	return MyCalendar{bookings: make([][2]int, 0)}
}

func (this *MyCalendar) Book(start int, end int) bool {
	for _, interval := range this.bookings {
		// Check for overlap
		if max(start, interval[0]) < min(end, interval[1]) {
			return false
		}
	}
	// Add the interval if no overlap is found
	this.bookings = append(this.bookings, [2]int{start, end})
	return true
}