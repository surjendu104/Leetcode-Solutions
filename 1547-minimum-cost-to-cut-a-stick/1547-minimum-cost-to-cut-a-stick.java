class Solution {
    static int f(int i, int j, int[] c, int[][] dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = Integer.MAX_VALUE;
        for(int k = i; k <= j; ++k) {
            int cost = (c[j+1]-c[i-1]) + f(i, k-1, c, dp) + f(k+1, j, c, dp);
            mini = Math.min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    public int minCost(int n, int[] cuts) {
        int x = cuts.length;
        int[][] dp = new int[x+2][x+2];
        
        int[] c = new int[x+2];
        c[0] = 0;
        c[x+1] = n;
        for(int i = 0; i < x; i++) c[i+1] = cuts[i];
        Arrays.sort(c);
        
        for(int i = x; i >= 1; --i) {
            for(int j = 1; j <= x; ++j) {
                if(i > j) continue;
                int mini = Integer.MAX_VALUE;
                for(int k = i; k <= j; ++k) {
                    int cost = (c[j+1]-c[i-1]) + dp[i][k-1] + dp[k+1][j];
                    mini = Math.min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][x];
    }
}