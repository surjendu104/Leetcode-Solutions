class Solution {
    int lengthOfLIS(int[] nums) {
        int n = nums.length;
        // int[][] dp = new int[n+1][n+1];
        int[] curr = new int[n+1];
        int[] next = new int[n+1];

        for(int i = n-1; i >= 0; --i) {
            for(int j = i-1; j >= -1; --j) {
                int len = next[j+1];
                if(j == -1 || nums[i] > nums[j])
                    len = Math.max(len, 1 + next[i+1]);
                curr[j+1] = len;
            }
            next = curr;
        }

        return curr[0];
    }
    /*
    // dp[i] :: length of LIS upto index i
    int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n+1];
        Arrays.fill(dp, 1);
        int len = Integer.MIN_VALUE;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i])dp[i] = Math.max(dp[i], 1+dp[j]);
            }
            len = Math.max(len, dp[i]);
        }
        return len;
    }
    */
}
