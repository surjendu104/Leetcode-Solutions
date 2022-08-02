class Solution {
    static int solve(int[] matrix, int m) {
        int low = 0, high = matrix.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid] <= m)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int i = matrix[0][0], j = matrix[n - 1][n - 1];

        while (i <= j) {
            int mid = i + (j - i) / 2;
            int c = 0;
            for (int m = 0; m < matrix.length; m++) {
                c += solve(matrix[m], mid);
            }
            if (c < k)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return i;

    }
}