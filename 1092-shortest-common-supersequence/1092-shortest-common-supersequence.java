class Solution {
    public String shortestCommonSupersequence(String s, String t) {
        int n = s.length(), m = t.length();
        int[][] dp = new int[n+1][m+1];
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                dp[i+1][j+1] = s.charAt(i) == t.charAt(j)
                               ? 1 + dp[i][j] 
                               : Math.max(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        // for(int[] it : dp) {
        //     for(int i : it) System.out.print(i+" ");
        //     System.out.println();
        // }
        
        int i = n, j = m;
        String ans = "";
        while(i> 0 && j > 0) {
            if(s.charAt(i-1) == t.charAt(j-1)) {
                ans += s.charAt(i-1);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans += s.charAt(i-1);
                i--;
            }else {
                ans += t.charAt(j-1);
                j--;
            }
        }
        while(i > 0) {
            ans+=s.charAt(i-1);
            i--;
        }
        while(j > 0) {
            ans+=t.charAt(j-1);
            j--;
        }
        ans = new StringBuilder(ans).reverse().toString();
        
        return ans;
    }
}