#include <bits/stdc++.h>
using namespace std;

// Recursion
// Giving TLE
class Solution
{
public:
    bool solve(string s1, string s2, string s3, int i, int j, int k)
    {
        if (i == s1.size() and j == s2.size() and k == s3.size())
            return true;
        if (k == s3.size())
            return false;

        if (s1[i] == s3[k] && solve(s1, s2, s3, i + 1, j, k + 1))
            return true;
        if (s2[j] == s3[k] && solve(s1, s2, s3, i, j + 1, k + 1))
            return true;

        return false;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;

        return solve(s1, s2, s3, 0, 0, 0);
    }
};

/*Runtime: 45 ms, faster than 25.29% of C++ online submissions for Interleaving String.
Memory Usage: 25.4 MB, less than 24.36% of C++ online submissions for Interleaving String.*/
class Solution
{
public:
    bool solve(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &dp)
    {
        if (i == s1.size() and j == s2.size() and k == s3.size())
            return true;
        if (k == s3.size())
            return false;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s3[k] && solve(s1, s2, s3, i + 1, j, k + 1, dp))
            return dp[i][j] = true;
        if (s2[j] == s3[k] && solve(s1, s2, s3, i, j + 1, k + 1, dp))
            return dp[i][j] = true;

        return dp[i][j] = false;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return solve(s1, s2, s3, 0, 0, 0, dp);
    }
};

/*Runtime: 7 ms, faster than 57.29% of C++ online submissions for Interleaving String.
Memory Usage: 6.7 MB, less than 66.40% of C++ online submissions for Interleaving String.*/
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size(), m = s2.size(), k = s3.size();

        if (n + m != k)
            return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        // dp[0][0] = 1;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                else
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
            }
        }
        return dp[n][m];
    }
};