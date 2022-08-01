class Solution
{
public:
    // Recursion
    int f(int m, int n, int i, int j)
    {
        if (i >= m or j >= n)
            return 0;
        if (i == m - 1 and j == n - 1)
            return 1;
        return f(m, n, i + 1, j) + f(m, n, i, j + 1);
    }

    // memoisation
    int f(int m, int n, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= m or j >= n)
            return 0;
        if (i == m - 1 and j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = f(m, n, i + 1, j, dp) + f(m, n, i, j + 1, dp);
    }

    int uniquePaths(int m, int n)
    {
        // return f(m,n,0,0);
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return f(m,n,0,0,dp);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 and j == 0)
                    continue;
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};