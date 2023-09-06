class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        int psum = 0;
        
        for(int i = 0; i < n; ++i) {
            psum += nums[i];
            psum %= k;
            
            if(psum == 0 && i != 0) return true;
            if(map.containsKey(psum)) {
                if(i-map.get(psum) > 1) return true;
            }
            else map.put(psum, i);
        }
        return false;
    }
}