class Solution {
    public void sortAll(int x, int y, int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] count = new int[101];

        for (int i = x, j = y; i < m && j < n; i++, j++) {
            count[mat[i][j]]++;
        }
        for (int i = 0; i < 101; i++) {
            while (count[i] != 0) {
                mat[x++][y++] = i;
                count[i]--;
            }
        }
    }

    public int[][] diagonalSort(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    sortAll(i, j, mat);
                }
            }
        }
        return mat;
    }
}