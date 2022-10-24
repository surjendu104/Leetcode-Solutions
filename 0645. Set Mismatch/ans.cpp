class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        int dup = -1, missing = 1;

        for (int i : nums)
        {
            if (nums[abs(i) - 1] < 0)
                dup = abs(i);
            else
            {
                nums[abs(i) - 1] *= (-1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                missing = i + 1;
        }
        return vector<int>{dup, missing};
    }
};
