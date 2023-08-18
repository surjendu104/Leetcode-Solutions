class Solution {
    public int longestCommonSubsequence(String s, String t) {
        int n = s.length(), m = t.length();
        // int[][] dp = new int[n+1][m+1];
        int[] curr = new int[m+1];
        int[] prev = new int[m+1];

        // for(int i = 0; i <= n; ++i) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) prev[j] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                curr[j] = s.charAt(i-1) == t.charAt(j-1) 
                                            ? 1+prev[j-1] : 
                                            Math.max(prev[j], curr[j-1]);
            }
            System.arraycopy(curr, 0, prev, 0, curr.length);
        }
        return prev[m];
    }
}