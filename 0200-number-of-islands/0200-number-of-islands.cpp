class Solution {
public:
    vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    void dfs(vector<vector<char>> &g, vector<vector<int>> &vis, int i, int j, int n, int m) {
        vis[i][j] = 1;
        for(int k = 0; k < 4; ++k) {
            int r = i + dir[k].first;
            int c = j + dir[k].second;
            if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && g[r][c] == '1') {
                dfs(g, vis, r, c, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid, vis, i, j, n, m); 
                    cnt++;
                }
            }
        }
        return cnt;
    }
};