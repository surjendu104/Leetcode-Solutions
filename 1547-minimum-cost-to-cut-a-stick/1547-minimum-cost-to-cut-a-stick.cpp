class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; len++) {
            for (int start = 0; start < m - len; start++) {
                int end = start + len;
                int minCost = INT_MAX;

                for (int k = start + 1; k < end; k++) {
                    int cost = cuts[end] - cuts[start];
                    int totalCost = dp[start][k] + dp[k][end];
                    minCost = min(minCost, totalCost + cost);
                }

                dp[start][end] = minCost;
            }
        }

        return dp[0][m - 1];
    }
};