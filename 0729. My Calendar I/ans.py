class MyCalendar:

    def __init__(self):
		# containing the start value of event
        self.starts = []
		# containing the end value of event
        self.ends = []
        
    def book(self, start: int, end: int) -> bool:
        
		# If there are no events,  just  append the value

        if not self.starts:
            self.starts.append(start)
            self.ends.append(end)
            return True
        
		# Else, find the index at which the start of the current event can be added by doing binary search 
		# if that index is == length of the array containing end values that means the start of our new event is bigger 
		# than end of any event present and we can simply add our event
		# otherwise we check what is the value of the start of the event at that index, if that is >=  current Event's end 
		# value we add the event at that particular index
		
        idx = bisect.bisect_right(self.ends, start)
        if idx == len(self.ends) or self.starts[idx] >= end:
            self.starts = self.starts[:idx] + [start] + self.starts[idx:]
            self.ends = self.ends[:idx] + [end] + self.ends[idx:]
            return True
        
        return False