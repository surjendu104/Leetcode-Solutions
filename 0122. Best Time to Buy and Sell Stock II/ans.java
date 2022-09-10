class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (prices[i] < prices[i + 1])
                ans += (prices[i + 1] - prices[i]);
        }
        return ans;
    }
}

/* DP */
// Memoisation

class Solution {
    public int f(int idx, int buy, int[] price, int n, int[][] dp) {
        if (idx == n)
            return 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];

        if (buy == 1) {
            dp[idx][buy] = Math.max(-price[idx] + f(idx + 1, 0, price, n, dp), 0 + f(idx + 1, 1, price, n, dp));
        } else
            dp[idx][buy] = Math.max(price[idx] + f(idx + 1, 1, price, n, dp), f(idx + 1, 0, price, n, dp));
        return dp[idx][buy];
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n][2];
        for (int[] i : dp) {
            Arrays.fill(i, -1);
        }
        f(0, 1, prices, n, dp);
        return dp[0][1];
    }
}

class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n + 1][2 + 1];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j >= 0; j--) {
                // buying
                if (j == 1) {
                    dp[i][j] = Math.max(-prices[i] + dp[i + 1][j - 1], dp[i + 1][j]);
                }
                // selling
                else {
                    dp[i][j] = Math.max(prices[i] + dp[i + 1][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][1];
    }
}