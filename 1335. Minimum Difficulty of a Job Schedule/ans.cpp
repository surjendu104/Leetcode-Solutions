class Solution
{
public:
    int solve(vector<int> &mat, vector<vector<int>> &ans, int n, int idx, int d)
    {
        if (d == 1)
            return *max_element(mat.begin() + idx, mat.end());

        if (ans[idx][d] != -1)
            return ans[idx][d];

        int Max = INT_MIN;
        int result = INT_MAX;

        for (int i = idx; i <= n - d; i++)
        {
            Max = max(Max, mat[i]);
            result = min(result, Max + solve(mat, ans, n, i + 1, d - 1));
        }
        return ans[idx][d] = result;
    }

    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (n < d)
            return -1;
        vector<vector<int>> ans(301, vector<int>(11, -1));
        return solve(jobDifficulty, ans, n, 0, d);
    }
};