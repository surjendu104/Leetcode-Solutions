class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int n = nums.length;
        int[] prefix_sum_mod_k = new int[k];
        int pre_sum = 0;

        for (int i = 0; i < n; i++) {
            pre_sum += nums[i];
            int rem = (pre_sum % k) < 0 ? (pre_sum % k) + k : (pre_sum % k);
            prefix_sum_mod_k[rem]++;
        }
        int ans = prefix_sum_mod_k[0];
        for (int i : prefix_sum_mod_k) {
            if (i >= 2)
                ans += i * (i - 1) * 0.5;
        }
        return ans;
    }
}