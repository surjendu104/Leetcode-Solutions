class Solution {
    int memo[20][10001];
    int dp(vector<int>& rods, int i, int balance) {
        if (i == rods.size()) return balance == 5000 ? 0 : INT_MIN;
        if (memo[i][balance] != -1) return memo[i][balance];

        int take = (dp(rods, i+1, balance + rods[i]) != INT_MIN ? dp(rods, i+1, balance + rods[i]) + rods[i] : INT_MIN);
        int give = dp(rods, i+1, balance - rods[i]);
        int skip = dp(rods, i+1, balance);

        memo[i][balance] = max(max(take, give), skip);
        return memo[i][balance];
    }
public:
    int tallestBillboard(vector<int>& rods) {
        fill_n(&memo[0][0], 20 * 10001, -1);
        return dp(rods, 0, 5000) != INT_MIN ? dp(rods, 0, 5000) : 0;
    }
};