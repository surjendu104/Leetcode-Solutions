class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& g) {
    int n = g.size(), m = g[0].size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    function<int(int, int)> ans = [&](int i, int j) -> int {
        if(i > n-1 || j > m-1) return 1e9;
        if(i == n-1 && j == m-1) return (g[i][j] <= 0) ? -g[i][j]+1 : 1;
        if(dp[i][j] != -1) return dp[i][j];

        int right = ans(i, j+1);
        int down = ans(i+1, j);

        int res = min(right, down) - g[i][j];
        
        return dp[i][j] = res <= 0 ? 1 : res;
    };
    return ans(0, 0);
}
};