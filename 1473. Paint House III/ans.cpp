#include<bits/stdc++.h>
using namespace std;

/*Runtime: 71 ms, faster than 92.29% of C++ online submissions for Paint House III.
Memory Usage: 10.9 MB, less than 58.78% of C++ online submissions for Paint House III.*/
class Solution
{
public:
    int dp[105][25][105];

    int solve(vector<int> &houses, int i, int n, int m, vector<vector<int>> &cost, int target, int prev_color)
    {
        // base case

        // if we have reached the end of the array and target == neighbors

        if (i == n && target == 0)
        {
            return 0;
        }

        // it means neighbors are greater than target

        if (i == n || target < 0)
            return INT_MAX;

        // if already calculated

        if (prev_color != -1 && target != -1 && dp[i][prev_color][target] != -1)
            return dp[i][prev_color][target];

        int min_cost = INT_MAX;

        // if houses[i] is already painted

        if (houses[i] != 0)
        {
            int temp_cost = 0;

            if (prev_color == houses[i]) // neighbors will remain same
            {
                temp_cost = solve(houses, i + 1, n, m, cost, target, houses[i]);
            }
            else // increase the neighbors
            {
                temp_cost = solve(houses, i + 1, n, m, cost, target - 1, houses[i]);
            }

            // update the min_cost

            min_cost = min(min_cost, temp_cost);
        }

        else // if houses[i] is not painted
        {
            // try out all the colors

            for (int j = 0; j < m; j++)
            {
                int temp_cost = 0;

                if (prev_color == j + 1) // neighbors will remain same
                {
                    temp_cost = solve(houses, i + 1, n, m, cost, target, j + 1);
                }
                else // increase the neighbors
                {
                    temp_cost = solve(houses, i + 1, n, m, cost, target - 1, j + 1);
                }

                // update the min_cost

                if (temp_cost != INT_MAX)
                {
                    min_cost = min(min_cost, cost[i][j] + temp_cost);
                }
            }
        }

        // store the calculated result

        if (prev_color != -1 && target != -1)
        {
            return dp[i][prev_color][target] = min_cost;
        }

        return min_cost;
    }

    int minCost(vector<int> &houses, vector<vector<int>> &cost, int n, int m, int target)
    {

        memset(dp, -1, sizeof(dp));

        int min_cost = solve(houses, 0, n, m, cost, target, -1);

        return min_cost == INT_MAX ? -1 : min_cost;
    }
};