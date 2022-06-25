/*Runtime: 7 ms, faster than 38.47% of C++ online submissions for Permutations.
Memory Usage: 7.7 MB, less than 55.64% of C++ online submissions for Permutations.*/
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ds;
        sort(nums.begin(), nums.end());
        do
        {
            ds.push_back(nums);

        } while (next_permutation(nums.begin(), nums.end()));
        return ds;
    }
};