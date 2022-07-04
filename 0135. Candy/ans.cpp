#include <bits/stdc++.h>
using namespace std;
/*Runtime: 31 ms, faster than 59.18% of C++ online submissions for Candy.
Memory Usage: 17.7 MB, less than 65.79% of C++ online submissions for Candy.*/
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candy(n, 1);

        for (int i = 0; i < n - 1; i++)
        {
            if (ratings[i] < ratings[i + 1])
            {
                candy[i + 1] = candy[i] + 1;
            }
        }

        for (int i = n - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i] && candy[i - 1] <= candy[i])
            {
                candy[i - 1] = candy[i] + 1;
            }
        }

        int ans = 0;

        for (int i : candy)
            ans += i;

        return ans;
    }
};