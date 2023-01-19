class Solution {
    public int minSubarray(int[] nums, int p) {
        int n = nums.length, mod = 0, need = 0, ans = nums.length;

        for (int i : nums) {
            mod = (mod + i) % p;
        }
        if (mod == 0)
            return 0;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);

        for (int i = 0; i < n; i++) {
            need = (need + nums[i]) % p;
            int comp = (p - mod + need) % p;

            if (map.containsKey(comp)) {
                ans = Math.min(ans, i - map.get(comp));
            }
            map.put(need, i);
        }
        return (ans >= n ? -1 : ans);
    }
}