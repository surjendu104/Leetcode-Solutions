class MyCalendar {
    ArrayList<ArrayList<Integer>> booked = new ArrayList<>();
    public MyCalendar() {
        
    }
    
    public boolean book(int start, int end) {
        for(int i=0;i<booked.size();i++){
            if(booked.get(i).get(0)< end && start<booked.get(i).get(1)){
                return false;
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(start);
        ans.add(end);
        booked.add(ans);
        return true;
    }
}


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */