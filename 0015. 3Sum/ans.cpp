#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n^2)
// space complexity: O(n)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        const int n = nums.size();
        unordered_map<int, int> c;
        for (int x : nums)
            ++c[x];
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i)
        {
            if (i && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; ++j)
            {
                if (j - 1 != i && nums[j] == nums[j - 1])
                    continue;
                const int t = 0 - nums[i] - nums[j];
                // nums[i] <= nums[j] <= nums[k]
                if (t < nums[j])
                    continue;
                if (!c.count(t))
                    continue;
                // Make sure we have enough count
                if (c[t] >= 1 + (nums[i] == t) + (nums[j] == t))
                    ans.push_back({nums[i], nums[j], t});
            }
        }
        return ans;
    }
};

/*Runtime: 161 ms, faster than 38.65% of C++ online submissions for 3Sum.
Memory Usage: 23.6 MB, less than 30.51% of C++ online submissions for 3Sum.*/

// Time complexity: O(n^2)
// space complexity: O(1)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int low = i + 1, high = nums.size() - 1, sum = 0 - nums[i];

                while (low < high)
                {
                    if (nums[low] + nums[high] == sum)
                    {
                        // ans.push_back({nums[i],nums[low],nums[high]});
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        while (low < high && nums[low] == nums[low + 1])
                            low++;
                        while (low < high && nums[high] == nums[high - 1])
                            high--;

                        low++;
                        high--;
                    }
                    else if (nums[low] + nums[high] < sum)
                        low++;
                    else
                        high--;
                }
            }
        }
        return ans;
    }
};


/*Runtime: 1295 ms, faster than 10.10% of C++ online submissions for 3Sum.
Memory Usage: 181.9 MB, less than 8.89% of C++ online submissions for 3Sum.*/
// Time complexity: O(n^2*logn)
// space complexity: O(n)+O(n)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            int a = nums[i];
            long long target = -a;
            int low = i + 1, high = n - 1;
            while (low < high)
            {
                long long sum = nums[low] + nums[high];
                if (sum == target)
                {
                    st.insert({a, nums[low], nums[high]});
                    low++;
                    high--;
                }
                else if (sum < target)
                    low++;
                else
                    high++;
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};