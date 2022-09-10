class Solution {
    public int fun(int e, int f, int[] dp) {
        if (f == 0 || f == 1)
            return f;
        if (e == 1)
            return f;
        if (dp[f] != -1)
            return dp[f];
        int mini = Integer.MAX_VALUE;
        for (int k = 1; k <= f; k++) {
            int temp = 1 + Math.max(fun(e - 1, k - 1, dp), fun(e, f - k, dp));
            mini = Math.min(temp, mini);
        }

        return dp[f] = mini;
    }

    public int twoEggDrop(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return fun(2, n, dp);
    }
}