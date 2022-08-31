class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &a)
    {
        if (vis[i][j])
            return;
        vis[i][j] = 1;
        if (i - 1 >= 0 && a[i][j] <= a[i - 1][j])
            dfs(i - 1, j, vis, a);
        if (j - 1 >= 0 && a[i][j] <= a[i][j - 1])
            dfs(i, j - 1, vis, a);
        if (i + 1 < vis.size() && a[i][j] <= a[i + 1][j])
            dfs(i + 1, j, vis, a);
        if (j + 1 < vis[0].size() && a[i][j] <= a[i][j + 1])
            dfs(i, j + 1, vis, a);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pacific(n, vector<int>(m, 0)), atlantic(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i)
        {
            dfs(i, 0, pacific, heights);
            dfs(i, m - 1, atlantic, heights);
        }

        for (int i = 0; i < m; ++i)
        {
            dfs(0, i, pacific, heights);
            dfs(n - 1, i, atlantic, heights);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};