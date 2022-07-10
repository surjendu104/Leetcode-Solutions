#include <bits/stdc++.h>
using namespace std;

/*Runtime: 17 ms, faster than 18.02% of C++ online submissions for Min Cost Climbing Stairs.
Memory Usage: 13.9 MB, less than 11.67% of C++ online submissions for Min Cost Climbing Stairs.*/
class Solution
{

public:
    int f(vector<int> &v, int i, int n, vector<int> &dp)
    {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        int l = v[i] + f(v, i + 1, n, dp);
        int r = v[i] + f(v, i + 2, n, dp);
        return dp[i] = min(l, r);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(f(cost, 0, n, dp), f(cost, 1, n, dp));
    }
};

/*Runtime: 22 ms, faster than 8.40% of C++ online submissions for Min Cost Climbing Stairs.
Memory Usage: 13.7 MB, less than 51.95% of C++ online submissions for Min Cost Climbing Stairs.*/
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n);

        for (int i = 0; i < n; i++)
        {
            if (i < 2)
                dp[i] = cost[i];
            else
                dp[i] = cost[i] + min(cost[i - 1], cost[i - 1]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

/*Runtime: 11 ms, faster than 53.51% of C++ online submissions for Min Cost Climbing Stairs.
Memory Usage: 13.7 MB, less than 51.95% of C++ online submissions for Min Cost Climbing Stairs.*/
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int prev = cost[0];
        int cur = cost[1];

        if (n <= 2)
            return min(cur, prev);

        for (int i = 2; i < n; i++)
        {
            int ans = cost[i] + min(cur, prev);
            prev = cur;
            cur = ans;
        }
        return min(prev, cur);
    }
};