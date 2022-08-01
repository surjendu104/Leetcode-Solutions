class Solution {
    static int f(int m, int n, int i, int j, int[][] dp) {
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = f(m, n, i + 1, j, dp) + f(m, n, i, j + 1, dp);
    }

    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        for (int row : dp)
            Arrays.fill(row, -1);

        return f(m, n, 0, 0, dp);

    }
}

class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                int right = 0, down = 0;
                if (i > 0)
                    down = dp[i - 1][j];
                if (j > 0)
                    right = dp[i][j - 1];
                dp[i][j] = right + down;
            }
        }
        return dp[m - 1][n - 1];
    }
}