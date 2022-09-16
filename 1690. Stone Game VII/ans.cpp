// Memoisation
class Solution
{
public:
    int f(vector<int> &s, int left, int right, int sum, vector<vector<int>> &dp)
    {
        if (left == right)
            return 0;
        if (right - left == 1)
            return max(s[right], s[left]);

        if (dp[left][right] != -1)
            return dp[left][right];

        return dp[left][right] = max(sum - s[left] - f(s, left + 1, right, sum - s[left], dp), sum - s[right] - f(s, left, right - 1, sum - s[right], dp));
    }
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(stones, 0, n - 1, sum, dp);
    }
};

