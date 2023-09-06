class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        int psum = 0, ans = 0;
        map.put(0, 1);
        for(int i = 0; i < n; ++i) {
            psum += nums[i];
            psum %= k;
            if(psum < 0) psum += k;
            
            if(map.containsKey(psum)) {
                ans += map.get(psum);
            }
            map.put(psum, 1+map.getOrDefault(psum, 0));
        }
        return ans;
    }
}