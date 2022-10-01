class Solution {
    public int solve(String s, int i, int[] dp) {
        int n = s.length();
        if (i == n)
            return dp[i] = 1;
        if (s.charAt(i) == '0')
            return dp[i] = 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = solve(s, i + 1, dp);

        if (i < n - 1 && (s.charAt(i) == '1' || (s.charAt(i) == '2' && s.charAt(i + 1) < '7')))
            ans += solve(s, i + 2, dp);
        return dp[i] = ans;
    }

    public int numDecodings(String s) {
        int[] dp = new int[s.length() + 1];
        Arrays.fill(dp, -1);
        return solve(s, 0, dp);
    }
}