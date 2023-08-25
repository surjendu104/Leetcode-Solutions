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
        int[][] dp = new int[x+1][x+1];
        for(int[] it : dp) Arrays.fill(it, -1);
        int[] c = new int[x+2];
        c[0] = 0;
        c[x+1] = n;
        for(int i = 0; i < x; i++) c[i+1] = cuts[i];
        Arrays.sort(c);
        return f(1, x, c, dp);
    }
}