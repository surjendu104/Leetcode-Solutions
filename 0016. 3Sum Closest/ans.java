class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int sum = 0;
        int x = Integer.MAX_VALUE;
        int ans = target;
        int n = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;

            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum == target)
                    return sum;
                int diff = Math.abs(sum - target);

                if (diff < x) {
                    x = diff;
                    ans = sum;
                }
                if (sum > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
}