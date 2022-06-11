#include <bits/stdc++.h>
using namespace std;

/*Runtime: 10 ms, faster than 63.13% of C++ online submissions for Minimum Size Subarray Sum.
Memory Usage: 10.6 MB, less than 17.75% of C++ online submissions for Minimum Size Subarray Sum.*/
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0, ans = INT_MAX;
        while (j < n)
        {
            sum += nums[j++];
            while (sum >= target)
            {
                sum -= nums[i++];
                ans = min(ans, j - i + 1);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};