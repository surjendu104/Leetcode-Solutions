/*Runtime: 92 ms, faster than 34.62% of C++ online submissions for K Inverse Pairs Array.
Memory Usage: 10.5 MB, less than 64.10% of C++ online submissions for K Inverse Pairs Array.*/

class Solution
{
public:
    int dp[1001][1001];
    int f(int n, int k)
    {
        long ans = 0;
        if (k == 0)
            return 1;
        if (k < 0 or n == 0)
            return 0;
        if (dp[n][k] != -1)
            return dp[n][k];
        ans = f(n - 1, k) + f(n, k - 1) - f(n - 1, k - n);
        return dp[n][k] = (int)((ans + 1000000007) % 1000000007);
    }
    int kInversePairs(int n, int k)
    {

        memset(dp, -1, sizeof(dp));

        return f(n, k);
    }
};

/*Runtime: 2800 ms, faster than 5.13% of C++ online submissions for K Inverse Pairs Array.
Memory Usage: 10.4 MB, less than 75.64% of C++ online submissions for K Inverse Pairs Array.*/
class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        int dp[1001][1001] = {1};
        for (int N = 1; N <= n; N++)
        {
            for (int K = 0; K <= k; K++)
            {
                for (int i = 0; i <= min(K, N - 1); i++)
                {
                    dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % 1000000007;
                }
            }
        }
        return dp[n][k];
    }
};