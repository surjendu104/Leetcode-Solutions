class Solution {
    static boolean check(String a, String b) {
        if(a.length() != b.length()+1) return false;
        int i = 0, j = 0;
        while(i < a.length()) {
            if(j < b.length() && a.charAt(i) == b.charAt(j)){
                i++;
                j++;
            }else {
                i++;
            }
        }
        if(i == a.length() && j == b.length()) return true;
        return false;
    }
    public int longestStrChain(String[] w) {
        int n = w.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        
        int maxi = Integer.MIN_VALUE;
        Arrays.sort(w, (a, b)-> a.length() - b.length());
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(check(w[i], w[j]) && dp[i] < 1+dp[j]) {
                    dp[i] = 1+dp[j];
                }
            }
            maxi = Math.max(maxi, dp[i]);
        }
        return maxi;
    }
}