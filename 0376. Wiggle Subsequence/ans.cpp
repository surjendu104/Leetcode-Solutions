#include <bits/stdc++.h>
using namespace std;

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Wiggle Subsequence.
Memory Usage: 7 MB, less than 95.64% of C++ online submissions for Wiggle Subsequence.*/
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int count = 1;
        int cur, prev = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            cur = nums[i] - nums[i - 1];
            if ((cur > 0 && prev <= 0) || (cur < 0 && prev >= 0))
            {
                count++;
                prev = cur;
            }
        }
        return count;
    }
};

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Wiggle Subsequence.
Memory Usage: 7.1 MB, less than 75.44% of C++ online submissions for Wiggle Subsequence.*/

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
                up = down + 1;
            else if (nums[i] > nums[i - 1])
                down = up + 1;
        }
        return max(up, down);
    }
};