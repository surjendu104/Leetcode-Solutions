// Runtime: 5 ms, faster than 100.00% of Java online submissions for Search a 2D Matrix II.
// Memory Usage: 48.1 MB, less than 96.47% of Java online submissions for Search a 2D Matrix II.
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for (int i = 0, j = matrix[0].length - 1; i < matrix.length && j >= 0;) {
            if (matrix[i][j] > target)
                j--;
            else if (matrix[i][j] < target)
                i++;
            else
                return true;
        }
        return false;
    }
}