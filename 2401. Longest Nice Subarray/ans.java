class Solution {
    public int longestNiceSubarray(int[] nums) {
        int check = 0, j = 0, ans = 0;
        for (int i = 0; i < nums.length; i++) {
            while ((check & nums[i]) != 0) {
                check ^= nums[j++];
            }
            check |= nums[i];
            ans = Math.max(ans, i - j + 1);
        }
        return ans;
    }
}