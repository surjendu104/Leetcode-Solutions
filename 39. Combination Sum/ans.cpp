
class Solution
{
public:
    void get_soln(vector<int> &candidates, int curr, int target, int curr_sum, vector<int> temp, vector<vector<int>> &ans)
    {
        // base cases
        if (curr_sum == target)
        {
            ans.push_back(temp);
            return;
        }
        if (curr_sum > target)
        {
            return;
        }
        if (curr == candidates.size())
        {
            return;
        }
        // recursive cases
        // include
        vector<int> a = temp;
        a.push_back(candidates[curr]);
        get_soln(candidates, curr, target, curr_sum + candidates[curr], a, ans);
        // exclude
        get_soln(candidates, curr + 1, target, curr_sum, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        get_soln(candidates, 0, target, 0, temp, ans);
        return ans;
    }
};