class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        int ans = nums[0];

        while (l <= r) {
            if (nums[l] < nums[r]) {
                ans = Math.min(ans, nums[l]);
            }
            int mid = (l + r) / 2;
            ans = Math.min(ans, nums[mid]);
            if (nums[mid] >= nums[r]) {
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }
}