class Solution {
    public int maximumProduct(int[] nums, int k) {
        int n = nums.length;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i : nums) pq.add(i);
        
        while(k != 0) {
            int x = pq.poll();
            pq.add(x+1);
            k--;
        }
        long ans = 1;
        int mod = 1000000007;
        while(!pq.isEmpty()) {
            ans = (ans*pq.peek())%mod;
            pq.poll();
        }
        return (int)ans;
    }
}