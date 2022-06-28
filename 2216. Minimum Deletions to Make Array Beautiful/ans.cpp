/*Runtime: 205 ms, faster than 91.59% of C++ online submissions for Minimum Deletions to Make Array Beautiful.
Memory Usage: 121.2 MB, less than 30.70% of C++ online submissions for Minimum Deletions to Make Array Beautiful.*/

class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        int n = nums.size(), i = 0, j = 1;
        int ans = 0;
        while (j < n)
        {
            if (nums[i] == nums[j])
            {
                ans++;
                j++;
            }
            else
            {
                i = j + 1;
                j += 2;
            }
        }
        if ((n - ans) % 2)
            ans++;
        return ans;
    }
};