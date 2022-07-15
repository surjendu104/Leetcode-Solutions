/*Runtime: 25 ms, faster than 70.89% of C++ online submissions for Max Area of Island.
Memory Usage: 23.2 MB, less than 89.29% of C++ online submissions for Max Area of Island.*/

class Solution
{
public:
    int ans = 0;
    void dfs(vector<vector<int>> &v, int i, int j, int &ans)
    {
        if (i < 0 || i >= v.size() || j < 0 || j >= v.size())
            return;
        if (v[i][j] == 0)
            return;
        v[i][j] = 0;
        ans++;
        dfs(v, i + 1, j, ans);
        dfs(v, i, j + 1, ans);
        dfs(v, i - 1, j, ans);
        dfs(v, i, j - 1, ans);
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    ans = 0;
                    dfs(grid, i, j, ans);
                    res = max(res, ans);
                }
            }
        }
        return res;
    }
};