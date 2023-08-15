class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n-k+1];
        int idx = 0;

        Deque<Integer> dq = new LinkedList<>();
        for(int i = 0; i < n; ++i) {
            if(!dq.isEmpty() && dq.peekFirst() == i-k) dq.pollFirst(); // remove out-of-window element
            
            while(!dq.isEmpty() && nums[dq.peekLast()] <= nums[i]) dq.pollLast();
            dq.offerLast(i);
            if(i >= k-1) ans[idx++] = nums[dq.peekFirst()];
        }

        return ans;
    }
}