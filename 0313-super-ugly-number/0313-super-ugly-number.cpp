class Solution {
public:
    long long solve(vector<long long>& dp, int n, int i, vector<int>& primes, vector<long long>& indices) {
        if (i == n) {
            return dp[n - 1];
        }

        long long nextUgly = INT_MAX;
        for (int j = 0; j < primes.size(); ++j) {
            nextUgly = min(nextUgly, dp[indices[j]] * primes[j]);
        }

        dp[i] = nextUgly;

        for (int j = 0; j < primes.size(); ++j) {
            if (dp[indices[j]] * primes[j] == nextUgly) {
                indices[j]++;
            }
        }

        return solve(dp, n, i + 1, primes, indices);
    }

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n, -1);
        dp[0] = 1;
        vector<long long> indices(primes.size(), 0);

        return solve(dp, n, 1, primes, indices);
    }
};