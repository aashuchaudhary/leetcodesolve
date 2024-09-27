type MyCalendarTwo struct {
	bookings map[int]int // Stores the start and end counts
}

func Constructor() MyCalendarTwo {
	return MyCalendarTwo{bookings: make(map[int]int)}
}

func (this *MyCalendarTwo) Book(start int, end int) bool {
	this.bookings[start]++
	this.bookings[end]--

	keys := make([]int, 0, len(this.bookings))
	for key := range this.bookings {
		keys = append(keys, key)
	}
	sort.Ints(keys)

	activeBookings := 0
	for _, time := range keys {
		activeBookings += this.bookings[time]
		if activeBookings >= 3 {
			// Revert the changes if triple booking is detected
			this.bookings[start]--
			this.bookings[end]++
			return false
		}
	}

	return true
}


/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(start,end);
 */