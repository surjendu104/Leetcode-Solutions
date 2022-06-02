class Solution
{
    void f(vector<int> &v, vector<int> ans, vector<vector<int>> &res, int n, int idx)
    {
        if (idx == n)
        {
            res.push_back(ans);
            return;
        }
        ans.push_back(v[idx]);
        f(v, ans, res, n, idx + 1);
        ans.pop_back();
        f(v, ans, res, n, idx + 1);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> res;
        f(nums, ans, res, n, 0);

        return res;
    }
};