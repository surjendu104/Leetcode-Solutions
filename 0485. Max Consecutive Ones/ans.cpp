class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0;
        int res = 0;
        for (int i : nums)
        {
            if (i == 1)
                ans++;
            if (i == 0)
            {
                ans = 0;
            }
            res = max(res, ans);
        }
        return res;
    }
};