class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        bool ans = next_permutation(nums.begin(), nums.end());
        if (ans)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i];
            }
        }
    }
};