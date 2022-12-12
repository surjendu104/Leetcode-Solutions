class Solution
{
public:
    int helper(int n, int idx, vector<int> &dp)
    {
        if (idx > n)
            return 0;
        if (idx == n)
            return 1;
        if (dp[idx] != -1)
            return dp[idx];
        dp[idx + 1] = helper(n, idx + 1, dp);
        dp[idx + 2] = helper(n, idx + 2, dp);

        return dp[idx] = dp[idx + 1] + dp[idx + 2];
    }
    int climbStairs(int n)
    {
        vector<int> dp(100, -1);
        return helper(n, 0, dp);
    }
};

//Tabulation

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)return n;

        vector<int> ans(n);
        ans[0] = 1;
        ans[1] = 2;
        for(int i=2;i<n;i++) {
            ans[i] = ans[i-1] + ans[i-2];
        }
        return ans[n-1];
    }
};