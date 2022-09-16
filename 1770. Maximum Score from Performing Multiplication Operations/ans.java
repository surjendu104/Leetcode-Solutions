class Solution {
    public int maximumScore(int[] nums, int[] multipliers) {
        int n=nums.length,m=multipliers.length;
        int[][] dp=new int[m+1][m+1];
        
        for(int[] i:dp){
            Arrays.fill(i,0);
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                int left = nums[j]*multipliers[i];
                int right = nums[(n-1)-(i-j)]*multipliers[i];
                
                dp[i][j] = Math.max(left+dp[i+1][j+1],right+dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
}