class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int maxi = 0;
        int[] dp = new int[n];
        int[] cnt = new int[n];
        for(int i = 0; i < n; ++i) {
            dp[i] = 1;
            cnt[i] = 1;
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j] && dp[i] < dp[j]+1) {
                    dp[i] = 1+dp[j];
                    cnt[i] = cnt[j];
                }else if(nums[i] > nums[j] && dp[i] == dp[j]+1) {
                    cnt[i]+=cnt[j];
                }
            }
            maxi = Math.max(maxi, dp[i]);
        }
        int num = 0;
        for(int i = 0; i < n; ++i) {
            if(dp[i] == maxi) num += cnt[i];
        }
        return num;
    }
}