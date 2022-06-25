/* Runtime: 47 ms, faster than 32.21% of C++ online submissions for Non-decreasing Array.
Memory Usage: 27 MB, less than 53.59% of C++ online submissions for Non-decreasing Array. */

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int c = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                if (c == 1)
                    return false;
                if (i < 2 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
                c++;
            }
        }
        return true;
    }
};