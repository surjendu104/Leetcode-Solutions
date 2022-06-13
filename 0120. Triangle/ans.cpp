// TC: O(n^2)
/*Runtime: 11 ms, faster than 37.61% of C++ online submissions for Triangle.
Memory Usage: 8.6 MB, less than 70.75% of C++ online submissions for Triangle.*/
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &t)
    {
        int n = t.size();
        vector<int> dp(t.back());
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[j] = min(dp[j], dp[j + 1]) + t[i][j];
            }
        }
        return dp[0];
    }
};