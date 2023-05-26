class Solution {
public:

    vector<int> pre;
    vector<vector<int>> dp;

    void initPrefix(vector<int> &piles) {
        int n = piles.size();
        pre = vector<int>(n + 1);
        dp = vector<vector<int>> (n, vector<int> (2 * n, -1));
        for(int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + piles[i - 1];
        }
    }

    int findSum(int lo, int hi) {
        return pre[hi + 1] - pre[lo];
    }

    int f(int taken, int m, int n, vector<int> &piles) {

        if(taken == n) {
            return 0;
        }

        if(dp[taken][m] != -1) {
            return dp[taken][m];
        }

        int res = -1e7;

        for(int i = 1; i <= 2 * m; i++) {
            int ind = taken + i - 1;
            if(ind >= n) break;
            res = max(res, findSum(taken, ind) - f(ind + 1, max(i, m), n, piles));
        }

        return dp[taken][m] = res;

    }

    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        initPrefix(piles);
        int ans = f(0, 1, n, piles);
        int sum = accumulate(piles.begin(), piles.end(), 0);
        ans = (sum + ans) / 2;
        return ans;
    }
};