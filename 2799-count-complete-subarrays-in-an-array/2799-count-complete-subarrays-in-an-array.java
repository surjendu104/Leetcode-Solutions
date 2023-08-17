class Solution {
    public int countCompleteSubarrays(int[] nums) {
        int i = 0, j = 0, n = nums.length;
        Set<Integer> set = new HashSet<>();
        for(int ii : nums)set.add(ii);
        int k = set.size();
        int ans = 0;
        
        Map<Integer, Integer> map = new HashMap<>();
        while(j < n) {
            map.put(nums[j], 1 + map.getOrDefault(nums[j], 0));
            while(map.size() == k) {
                ans+= nums.length-j;
                map.put(nums[i], map.get(nums[i]) - 1);
                if(map.get(nums[i]) == 0) map.remove(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
}