class Solution {
    public int solve(int idx, int tranNo, int[] price, int n, int k, int[][] dp) {
        if (idx == n || tranNo == 2 * k)
            return 0;

        if (dp[idx][tranNo] != -1)
            return dp[idx][tranNo];

        if (tranNo % 2 == 0) {
            return dp[idx][tranNo] = Math.max(-price[idx] + solve(idx + 1, tranNo + 1, price, n, k, dp),
                    0 + solve(idx + 1, tranNo, price, n, k, dp));
        }
        return dp[idx][tranNo] = Math.max(price[idx] + solve(idx + 1, tranNo + 1, price, n, k, dp),
                solve(idx + 1, tranNo, price, n, k, dp));
    }

    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        if (n == 0 || k == 0)
            return 0;
        int[][] dp = new int[n][2 * k];
        for (int[] i : dp) {
            Arrays.fill(i, -1);
        }
        solve(0, 0, prices, prices.length, k, dp);

        // for(int[] i:dp){
        // for(int j:i){
        // System.out.print(j+" ");
        // }
        // System.out.print("\n");
        // }
        return dp[0][0];
    }
}

// Tabulation

class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;

        int[][] dp = new int[n + 1][2 * k + 1];

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int tranNo = 2 * k - 1; tranNo >= 0; tranNo--) {
                if (tranNo % 2 == 0) {
                    dp[idx][tranNo] = Math.max(-prices[idx] + dp[idx + 1][tranNo + 1], dp[idx + 1][tranNo]);
                } else {
                    dp[idx][tranNo] = Math.max(prices[idx] + dp[idx + 1][tranNo + 1], dp[idx + 1][tranNo]);
                }
            }
        }
        return dp[0][0];
    }
}