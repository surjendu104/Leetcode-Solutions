#include <bits/stdc++.h>
using namespace std;

// Recursive
// TLE
//TC : O(2^n)
class Solution
{
    int lcs(string &s, string &t, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;
        else if (s[n - 1] == t[m - 1])
            return 1 + lcs(s, t, n - 1, m - 1);
        else
            return max(lcs(s, t, n - 1, m), lcs(s, t, n, m - 1));
    }

public:
    int minDistance(string word1, string word2)
    {
        int ans = lcs(word1, word2, word1.size(), word2.size());
        return (word1.size() + word2.size()) - (2 * ans);
    }
};

// Memoisation
/*Runtime: 41 ms, faster than 30.19% of C++ online submissions for Delete Operation for Two Strings.
Memory Usage: 12.4 MB, less than 10.07% of C++ online submissions for Delete Operation for Two Strings.*/
//TC : O(nm)
class Solution
{
    int lcs(string &s, string &t, int n, int m, vector<vector<int>> &dp)
    {
        if (n == 0 || m == 0)
            return 0;
        if (s[n - 1] == t[m - 1])
            dp[n][m] = 1 + lcs(s, t, n - 1, m - 1, dp);
        if (dp[n][m] != -1)
            return dp[n][m];
        else
            dp[n][m] = max(lcs(s, t, n - 1, m, dp), lcs(s, t, n, m - 1, dp));
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = lcs(word1, word2, n, m, dp);
        return (word1.size() + word2.size()) - (2 * ans);
    }
};

// Tabulation
/*Runtime: 30 ms, faster than 52.16% of C++ online submissions for Delete Operation for Two Strings.
Memory Usage: 12.3 MB, less than 17.03% of C++ online submissions for Delete Operation for Two Strings.*/
//TC : O(nm)
class Solution
{
    int lcs(string &s, string &t, int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                if (s[i] == t[j])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = lcs(word1, word2, n, m);
        return (word1.size() + word2.size()) - (2 * ans);
    }
};