#include <bits/stdc++.h>
using namespace std;

// Resursion
class Solution
{
public:
    int lcs(string &a, string &b, int i, int j)
    {
        if (i == a.size() || j == b.size())
            return 0;
        else if (a[i] == b[j])
        {
            return 1 + lcs(a, b, i + 1, j + 1);
        }
        else
        {
            return max(lcs(a, b, i + 1, j), lcs(a, b, i, j + 1));
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        return lcs(text1, text2, 0, 0);
    }
};

// Memoisation
class Solution
{
public:
    int lcs(string &a, string &b, vector<vector<int>> &dp, int i, int j)
    {
        if (i == a.size() || j == b.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        else if (a[i] == b[j])
        {
            return 1 + lcs(a, b, dp, i + 1, j + 1);
        }
        else
        {
            return max(lcs(a, b, dp, i + 1, j), lcs(a, b, dp, i, j + 1));
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(1000, vector<int>(1000, -1));
        return lcs(text1, text2, dp, 0, 0);
    }
};

// Tabulation
// Accepted
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int res[1001][1001] = {};
        for (int i = 0; i < text1.size(); i++)
        {
            for (int j = 0; j < text2.size(); j++)
            {
                res[i + 1][j + 1] = (text1[i] == text2[j]) ? (1 + res[i][j]) : max(res[i + 1][j], res[i][j + 1]);
            }
        }
        return res[text1.size()][text2.size()];
    }
};