#include <bits/stdc++.h>
using namespace std;

/*
Runtime: 78 ms, faster than 66.42% of C++ online submissions for 4Sum.
Memory Usage: 13.1 MB, less than 89.87% of C++ online submissions for 4Sum. */
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        if (nums.empty())
            return ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = target - nums[i] - nums[j];
                int low = j + 1, high = n - 1;
                while (low < high)
                {
                    if (nums[low] + nums[high] > sum)
                    {
                        high--;
                    }
                    else if (nums[low] + nums[high] < sum)
                        low++;
                    else
                    {
                        vector<int> temp(4, 0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[low];
                        temp[3] = nums[high];
                        ans.push_back(temp);
                        low++;
                        high--;
                        while (low < high && nums[low] == temp[2])
                            low++;
                        while (low < high && nums[high] == temp[3])
                            high--;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j])
                    j++;
            }
            while (i + 1 < n && nums[i + 1] == nums[i])
                i++;
        }
        return ans;
    }
};