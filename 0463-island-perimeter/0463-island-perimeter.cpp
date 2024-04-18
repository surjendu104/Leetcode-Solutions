#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int count = 0;

    void dfs(vector<vector<int>>& g, vector<vector<int>>& vis, int i, int j, int n, int m) {
        vis[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            int r = i + dir[k].first;
            int c = j + dir[k].second;
            if (r < 0 || r >= n || c < 0 || c >= m || g[r][c] == 0) {
                count++;
            } else if (!vis[r][c]) {
                dfs(g, vis, r, c, n, m);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    dfs(grid, vis, i, j, n, m);
                    return count;
                }
            }
        }
        return count;
    }
};
