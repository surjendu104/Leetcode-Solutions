// dp

class Solution
{
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        // base conditions
        if (i >= m or j >= n)
            return 0;
        if (i == m - 1 and j == n - 1)
            return 1;

        /**/
        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = solve(i + 1, j, m, n, dp) + solve(i, j + 1, m, n, dp);
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, m, n, dp);
    }
};