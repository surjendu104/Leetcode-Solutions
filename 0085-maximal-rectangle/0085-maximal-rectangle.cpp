class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        int ans = 0;
        unordered_map<pair<int, int>, pair<int, int>, PairHash> dp;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    dp[{i, j}] = {0, 0};
                } else {
                    int x = (j > 0) ? dp[{i, j - 1}].first + 1 : 1;
                    int y = (i > 0) ? dp[{i - 1, j}].second + 1 : 1;
                    dp[{i, j}] = {x, y};
                    ans = max({x, y, ans});
                    int minWidth = x;
                    for (int r = i - 1; r >= i - y + 1; --r) {
                        minWidth = min(minWidth, dp[{r, j}].first);
                        ans = max(ans, minWidth * (i - r + 1));
                    }
                }
            }
        }

        return ans;
    }
private:
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
};
