#include <bits/stdc++.h>
using namespace std;

/*Runtime: 613 ms, faster than 25.28% of C++ online submissions for Minimum Operations to Reduce X to Zero.
Memory Usage: 168.2 MB, less than 14.25% of C++ online submissions for Minimum Operations to Reduce X to Zero.*/
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            mpp[sum] = i;
        }
        int target = sum - x;
        sum = 0;
        int ans = INT_MIN;
        if (target < 0)
            return -1;
        mpp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (mpp.find(sum - target) != mpp.end())
            {
                ans = max(ans, i - mpp[sum - target]);
            }
        }

        return ans == INT_MIN ? -1 : n - ans;
    }
};

/*Runtime: 187 ms, faster than 86.49% of C++ online submissions for Minimum Operations to Reduce X to Zero.
Memory Usage: 98.6 MB, less than 71.00% of C++ online submissions for Minimum Operations to Reduce X to Zero.*/
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = 0, n = nums.size();
        for (int i : nums)
            sum += i;

        int target = sum - x;
        if (target < 0)
            return -1;

        sum = 0;
        int left = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (sum > target)
            {
                sum -= nums[left++];
            }
            if (sum == target)
            {
                ans = max(ans, i - left + 1);
            }
        }
        return ans == INT_MIN ? -1 : n - ans;
    }
};