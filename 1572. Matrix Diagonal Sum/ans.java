class Solution {
    public int diagonalSum(int[][] mat) {
        int n = mat.length;
        int j = n - 1;
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += mat[i][i];
            s += mat[i][j];
            j--;
        }
        if (n % 2 != 0)
            return s - mat[n / 2][n / 2];
        return s;
    }
}