class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length(), m = text2.length();
        int[][] res = new int[n + 1][m + 1];
        for (int[] i : res) {
            Arrays.fill(i, 0);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i + 1][j + 1] = (text1.charAt(i) == text2.charAt(j)) ? (1 + res[i][j])
                        : Math.max(res[i + 1][j], res[i][j + 1]);
            }
        }
        return res[n][m];
    }
}