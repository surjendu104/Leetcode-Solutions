#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution
{
public:
    int f(vector<int> &v, vector<int> &m, int idx, int i, int j)
    {
        if (idx == m.size())
            return 0;

        int left = (m[idx] * v[i]) + f(v, m, idx + 1, i + 1, j);

        int right = (m[idx] * v[j]) + f(v, m, idx + 1, i, j - 1);
        return max(right, left);
    }

    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size();
        return f(nums, multipliers, 0, 0, n - 1);
    }
};

// Memoisation
class Solution
{
    int f(vector<int> &v, vector<int> &m, int idx, int i, int n, vector<vector<int>> &dp)
    {
        if (idx == m.size())
            return 0;
        if (dp[i][idx] != -1)
            return dp[i][idx];

        int left = (m[idx] * v[i]) + f(v, m, idx + 1, i + 1, n, dp);

        int right = (m[idx] * v[n - 1 - (idx - i)]) + f(v, m, idx + 1, i, n, dp);
        return dp[i][idx] = max(right, left);
    }

public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        return f(nums, multipliers, 0, 0, n, dp);
    }
};

// Tabulation
/*Runtime: 862 ms, faster than 20.90% of C++ online submissions for Maximum Score from Performing Multiplication Operations.
Memory Usage: 173.2 MB, less than 40.26% of C++ online submissions for Maximum Score from Performing Multiplication Operations.*/
class Solution
{
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int m = multipliers.size(), n = nums.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int l = multipliers[i] * nums[j];
                int r = multipliers[i] * nums[n - 1 - (i - j)];
                dp[i][j] = max(l + dp[i + 1][j + 1], r + dp[i + 1][j]);
            }
        }
        return dp[0][0];
    }
};
