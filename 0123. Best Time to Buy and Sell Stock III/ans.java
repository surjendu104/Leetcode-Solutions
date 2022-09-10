
//using 3d dp
class Solution {
    public int f(int idx, int buy, int trnNo, int[] price, int n, int k, int[][][] dp) {
        if (idx == n || trnNo == 2 * k)
            return 0;
        if (dp[idx][buy][trnNo] != -1)
            return dp[idx][buy][trnNo];
        if (buy == 1) {
            dp[idx][buy][trnNo] = Math.max(-price[idx] + f(idx + 1, 0, trnNo + 1, price, n, k, dp),
                    f(idx + 1, 1, trnNo, price, n, k, dp));
        } else
            dp[idx][buy][trnNo] = Math.max(price[idx] + f(idx + 1, 1, trnNo + 1, price, n, k, dp),
                    f(idx + 1, 0, trnNo, price, n, k, dp));
        return dp[idx][buy][trnNo];
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;

        int[][][] dp = new int[n][2][4];

        for (int[][] i : dp) {
            for (int[] j : i)
                Arrays.fill(j, -1);
        }
        return f(0, 1, 0, prices, n, 2, dp);
    }
}

class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;

        int[][][] dp = new int[n + 1][2 + 1][4 + 1];

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 1; buy >= 0; buy--) {
                for (int trnNo = 3; trnNo >= 0; trnNo--) {
                    if (buy == 1)
                        dp[idx][buy][trnNo] = Math.max(-prices[idx] + dp[idx + 1][buy - 1][trnNo + 1],
                                dp[idx + 1][buy][trnNo]);
                    else
                        dp[idx][buy][trnNo] = Math.max(prices[idx] + dp[idx + 1][buy + 1][trnNo + 1],
                                dp[idx + 1][buy][trnNo]);
                }
            }
        }
        return dp[0][1][0];
    }
}

// 2d dp
// we are buying when transaction no is even index and selling it in odd index
class Solution {
    public int solve(int idx, int tranNo, int[] price, int n, int[][] dp) {
        if (idx == n || tranNo == 4)
            return 0;

        if (dp[idx][tranNo] != -1)
            return dp[idx][tranNo];

        if (tranNo % 2 == 0) {
            return dp[idx][tranNo] = Math.max(-price[idx] + solve(idx + 1, tranNo + 1, price, n, dp),
                    0 + solve(idx + 1, tranNo, price, n, dp));
        }
        return dp[idx][tranNo] = Math.max(price[idx] + solve(idx + 1, tranNo + 1, price, n, dp),
                solve(idx + 1, tranNo, price, n, dp));
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        if (n == 0)
            return 0;
        int[][] dp = new int[n][4];
        for (int[] i : dp) {
            Arrays.fill(i, -1);
        }
        solve(0, 0, prices, prices.length, dp);

        // for(int[] i:dp){
        // for(int j:i){
        // System.out.print(j+" ");
        // }
        // System.out.print("\n");
        // }
        return dp[0][0];
    }
}

class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n + 1][4 + 1];

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int trnNo = 3; trnNo >= 0; trnNo--) {
                if (trnNo % 2 == 0)
                    dp[idx][trnNo] = Math.max(-prices[idx] + dp[idx + 1][trnNo + 1], dp[idx + 1][trnNo]);
                else
                    dp[idx][trnNo] = Math.max(prices[idx] + dp[idx + 1][trnNo + 1], dp[idx + 1][trnNo]);
            }
        }

        return dp[0][0];
    }
}
