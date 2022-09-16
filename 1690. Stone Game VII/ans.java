import java.util.Arrays;

// Memoisation
class Solution {
    public int f(int[] s, int left, int right, int sum, int[][] dp) {
        if (left == right)
            return 0;
        if (right - left == 1)
            return Math.max(s[right], s[left]);

        if (dp[left][right] != -1)
            return dp[left][right];

        return dp[left][right] = Math.max(sum - s[left] - f(s, left + 1, right, sum - s[left], dp),
                sum - s[right] - f(s, left, right - 1, sum - s[right], dp));
    }

    public int stoneGameVII(int[] stones) {
        int n = stones.length;
        int sum = 0;
        for (int i : stones)
            sum += i;
        int[][] dp = new int[n + 1][n + 1];
        for (int[] i : dp) {
            Arrays.fill(i, -1);
        }
        return f(stones, 0, n - 1, sum, dp);
    }
}
