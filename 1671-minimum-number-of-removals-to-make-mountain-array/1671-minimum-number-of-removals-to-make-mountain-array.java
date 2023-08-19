class Solution {
    int[] LIS(int[] a, int n) {
        int[] dp = new int[n];
        
        for(int i = 0; i < n; ++i) {
            dp[i] = 1;
            for(int j = 0; j < i; ++j) {
                if(a[i] > a[j]) dp[i] = Math.max(dp[i], 1+dp[j]);
            }
        }
        return dp;
    }
    public int minimumMountainRemovals(int[] nums) {
        int n = nums.length;
        int[] dp1 = LIS(nums, n);
        
        int[] tmp = new int[n];
        for(int i = n-1; i >= 0; --i) tmp[n-i-1] = nums[i];
        int[] dp2 = LIS(tmp, n);
        
        int maxi = 0;
        for(int i = 0; i < n; ++i) {
            if(dp1[i]>1 && dp2[n-i-1] >1)maxi = Math.max(maxi, dp1[i]+dp2[n-i-1]-1);
        }
        // System.out.println("dbg : "+maxi);
        return n-maxi;
    }
}