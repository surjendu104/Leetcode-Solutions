// Recursion
class Solution
{
    int f(vector<vector<int>> &v, int i, int j, int m, int n)
    {
        if (i >= 0 && j >= 0 && v[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return dp[i][j] = 1;
        if (i < 0 || j < 0)
            return 0;

        int l = f(v, i - 1, j, m, n), r = f(v, i, j - 1, m, n);
        return l + r;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &g)
    {

        int m = g.size(), n = g[0].size();
        return f(g, m - 1, n - 1, m - 1, n - 1);
    }
};
// Memoisation
class Solution
{
    int f(vector<vector<int>> &v, int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i >= 0 && j >= 0 && v[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return dp[i][j] = 1;
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int l = f(v, i - 1, j, m, n, dp), r = f(v, i, j - 1, m, n, dp);
        return dp[i][j] = l + r;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &g)
    {

        int m = g.size(), n = g[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(g, m - 1, n - 1, m - 1, n - 1, dp);
    }
};

// Tabulation

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &g)
    {
        int m = g.size(), n = g[0].size();
        int dp[m][n];
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (g[i][j] == 1)
                    dp[i][j] = 0;
                else if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    int l = 0, r = 0;
                    if (i > 0)
                        l = dp[i - 1][j];
                    if (j > 0)
                        r = dp[i][j - 1];
                    dp[i][j] = l + r;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};