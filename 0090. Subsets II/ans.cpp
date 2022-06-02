class Solution
{
    void f(vector<int> &v, vector<int> &ans, vector<vector<int>> &res, int idx)
    {
        res.push_back(ans);

        for (int i = idx; i < v.size(); i++)
        {
            if (i != idx && v[i] == v[i - 1])
                continue;
            ans.push_back(v[i]);
            f(v, ans, res, i + 1);
            ans.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> ans;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        f(nums, ans, res, 0);

        return res;
    }
};
