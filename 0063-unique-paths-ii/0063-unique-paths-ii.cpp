class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>dp) {
        if(i ==m || j==n)return 0;
        if(grid[i][j] == 1)return 0;
        if(i == m-1 && j == n-1)return 1;
        if(dp[i][j] != -1)return dp[i][j];
        
        int left = 0, right = 0;
        if(i < m) left = solve(grid, i+1, j, m, n, dp);
        if(j < n) right = solve(grid, i, j+1, m, n, dp);
        
        return dp[i][j] = left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        
        if(obstacleGrid[0][0] == 1)return 0;
        else dp[0][0] = 1;
        for(int i = 0; i < m;i++) {
            for(int j = 0; j < n; ++j) {
                if(i ==0 && j == 0)continue;
                if(i > 0 && obstacleGrid[i][j] != 1)dp[i][j] += dp[i-1][j];
                if(j > 0 && obstacleGrid[i][j] != 1)dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};