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

/*
 * Approach : Generate all subarray and then check the condition
 * Fate : It will give write answer on small testcase but give stackoverflow in
 * bigger testcases
 */
class Solution {
    int ans = 0;

    public void helper(int[] nums, int k, int start, int end) {
        if (end == nums.length)
            return;
        else if (start > end)
            helper(nums, k, 0, end + 1);
        else {
            int sum = 0;
            for (int i = start; i <= end; i++)
                sum += nums[i];
            if (sum % k == 0)
                ans++;
            helper(nums, k, start + 1, end);
        }
    }

    public int subarraysDivByK(int[] nums, int k) {
        helper(nums, k, 0, 0);
        return ans;
    }
}