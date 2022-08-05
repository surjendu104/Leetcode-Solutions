#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int target, vector<int> &dp)
    {
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;
        if (dp[target] != -1)
            return dp[target];
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += solve(nums, target - nums[i], dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            int ans = 0;
            for (int x : nums)
            {
                if (i >= x)
                {
                    ans += dp[i - x];
                }
            }
            dp[i] = ans;
        }
        return dp[target];
    }
};