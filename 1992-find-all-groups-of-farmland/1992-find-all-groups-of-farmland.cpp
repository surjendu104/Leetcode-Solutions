class Solution {
public:
    vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void dfs(vector<vector<int>> &g, vector<vector<int>> &vis, int i, int j, int &r1, int &c1, int &r2, int &c2, int n, int m) {
        vis[i][j] = 1;
        r1 = min(r1, i);
        c1 = min(c1, j);
        r2 = max(r2, i);
        c2 = max(c2, j);
        for(int k = 0; k < 4; ++k) {
            int r = i + dir[k].first;
            int c = j + dir[k].second;
            if(isValid(r, c, n, m) && !vis[r][c] && g[r][c] == 1) {
                    
                dfs(g, vis, r, c, r1, c1, r2, c2, n, m);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(land[i][j] == 1 && !vis[i][j]) {
                    int r1 =i, r2 = i;
                    int c1 = j, c2 = j;
                    dfs(land, vis, i, j, r1, c1, r2, c2, n, m);
                    ans.push_back({r1, c1, r2, c2});
                }
            }
        }
        return ans;
    }
};