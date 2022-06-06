class Solution
{
public:
    int minMaxGame(vector<int> &nums)
    {
        int n = nums.size();
        if (nums.size() == 1)
            return nums[0];
        vector<int> num(n / 2);
        for (int i = 0; i < n / 2; i++)
        {
            num[i] = (i % 2 == 1) ? (max(nums[2 * i], nums[2 * i + 1])) : (min(nums[2 * i], nums[2 * i + 1]));
        }
        int ans = minMaxGame(num);
        return ans;
    }
};