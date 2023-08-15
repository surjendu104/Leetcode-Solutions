class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            if(sum == k) ans++;
            // sum-k present in map
            if(map.get(sum-k) != null) ans+=map.get(sum-k);
            // sum not present in map
            if(map.get(sum) == null) map.put(sum, 1); 
            else map.put(sum, map.get(sum)+1);
        }
        return ans;
    }
}