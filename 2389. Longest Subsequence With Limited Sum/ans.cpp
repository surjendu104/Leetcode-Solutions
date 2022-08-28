class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> ans(queries.size(), 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < queries.size(); i++)
        {
            int s = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                s += nums[j];
                if (s <= queries[i])
                    ans[i] = j + 1;
            }
        }
        return ans;
    }
};