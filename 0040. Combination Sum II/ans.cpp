#include <bits/stdc++.h>
using namespace std;
/*Runtime: 9 ms, faster than 58.11% of C++ online submissions for Combination Sum II.
Memory Usage: 10.6 MB, less than 70.61% of C++ online submissions for Combination Sum II.*/
class Solution
{
    void f(vector<int> &v, vector<int> &ans, vector<vector<int>> &res, int curSum, int idx, int target)
    {
        if (curSum == target)
        {
            res.push_back(ans);
            return;
        }
        if (idx >= v.size())
            return;
        if (curSum > target)
            return;

        curSum += v[idx];
        ans.push_back(v[idx]);
        f(v, ans, res, curSum, idx + 1, target);

        // not take
        curSum -= v[idx];
        ans.pop_back();

        while (idx + 1 < v.size() && v[idx] == v[idx + 1])
            idx++;
        f(v, ans, res, curSum, idx + 1, target);
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> ans;
        vector<vector<int>> res;
        f(candidates, ans, res, 0, 0, target);
        return res;
    }
};