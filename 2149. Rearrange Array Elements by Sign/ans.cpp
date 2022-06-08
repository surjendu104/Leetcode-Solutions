#include <bits/stdc++.h>
using namespace std;


/*Runtime: 345 ms, faster than 26.10% of C++ online submissions for Rearrange Array Elements by Sign.
Memory Usage: 123.6 MB, less than 99.50% of C++ online submissions for Rearrange Array Elements by Sign.*/
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> positive, negative;
        for (int i : nums)
        {
            if (i >= 0)
                positive.push_back(i);
            else
                negative.push_back(i);
        }
        int low = 0, i = 0, j = 0;
        while (low != n)
        {
            if (low % 2 == 0)
                nums[low++] = positive[i++];
            else
                nums[low++] = negative[j++];
        }
        return nums;
    }
};


/*Runtime: 345 ms, faster than 26.10% of C++ online submissions for Rearrange Array Elements by Sign.
Memory Usage: 123.6 MB, less than 99.50% of C++ online submissions for Rearrange Array Elements by Sign.*/

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int i = 0, j = 1;
        vector<int> ans(nums.size());
        for (int x : nums)
        {
            if (x > 0)
            {
                ans[i] = x;
                i += 2;
            }
            else
            {
                ans[j] = x;
                j += 2;
            }
        }
        return ans;
    }
};