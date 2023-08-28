class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int> (m+1, -1)));

        function<int(int, int, int)> dfs = [&](int i, int j1, int j2)->int {
            if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;
            if(i == n-1) {
                if(j1 == j2) return grid[i][j1];
                else return grid[i][j1]+grid[i][j2];
            }
            if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
            int maxi = -1e9;
            for(int dj1 = -1; dj1 <= 1; dj1++) {
                for(int dj2 = -1; dj2 <= 1; dj2++) {
                    int val = 0;
                    if(j1 == j2) val = grid[i][j1];
                    else val = grid[i][j1] + grid[i][j2];
                    val += dfs(i+1, j1+dj1, j2+dj2);
                    maxi = max(maxi, val);
                }
            }
            return dp[i][j1][j2] = maxi;
        };
        return dfs(0, 0, m-1); 
    }
};