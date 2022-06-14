#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int match(string &s, string &t, int n, int m)
    {
        if (n == 0)
            return m;
        if (m == 0)
            return n;

        if (s[n - 1] == t[m - 1])
            return match(s, t, n - 1, m - 1);
        return min(match(s, t, n, m - 1), min(match(s, t, n - 1, m - 1), match(s, t, n - 1, m)));
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        return match(word1, word2, n, m);
    }
};

// Memoisation
/*Runtime: 15 ms, faster than 69.43% of C++ online submissions for Edit Distance.
Memory Usage: 9.1 MB, less than 20.57% of C++ online submissions for Edit Distance.*/
class Solution
{

    int match(string &s, string &t, int n, int m, vector<vector<int>> &dp)
    {
        if (n == 0)
            return m;
        if (m == 0)
            return n;

        if (dp[n][m] != -1)
            return dp[n][m];
        if (s[n - 1] == t[m - 1])
        {
            dp[n][m] = match(s, t, n - 1, m - 1, dp);
            return dp[n][m];
        }
        dp[n][m] = 1 + min(match(s, t, n, m - 1, dp), min(match(s, t, n - 1, m - 1, dp), match(s, t, n - 1, m, dp)));
        return dp[n][m];
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return match(word1, word2, n, m, dp);
    }
};

// Tabulation
class Solution
{

    int match(string &s, string &t, int n, int m)
    {
        vector<vector<int>> dp(n + 2, vector<int>(m + 2, -1));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= m; i++)
            dp[0][i] = i;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
        return dp[n][m];
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        return match(word1, word2, n, m);
    }
};