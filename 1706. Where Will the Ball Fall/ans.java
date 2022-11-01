class Solution {
    public int[] findBall(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[] ans = new int[m];

        for (int ball = 0; ball < m; ball++) {
            int i = 0, j = ball, f = 0;
            while (i < n) {
                if (grid[i][j] == 1) {
                    if (j == m - 1 || grid[i][j + 1] == -1) {
                        f = 1;
                        break;
                    }
                    i++;
                    j++;
                } else {
                    if (j == 0 || grid[i][j - 1] == 1) {
                        f = 1;
                        break;
                    }
                    i++;
                    j--;
                }
            }
            ans[ball] = (f == 1) ? -1 : j;
        }
        return ans;
    }
}

// Recursion
class Solution {
    public int[] findBall(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] res = new int[n];

        for (int i = 0; i < n; i++) { // traverse each ball starting from each col
            res[i] = helper(grid, 0, i);
        }
        return res;
    }

    private int helper(int[][] grid, int row, int col) {
        if (row == grid.length)
            return col;
        int cur = grid[row][col];
        if (cur == 1) {
            if (col == grid[0].length - 1 || grid[row][col + 1] == -1) { // blocked by 'V' or the right wall
                return -1;
            } else {
                return helper(grid, row + 1, col + 1); // col + 1 because cur == 1, goes to next col
            }
        } else if (cur == -1) {
            if (col == 0 || grid[row][col - 1] == 1) { // blocked by 'V' or the left wall
                return -1;
            } else {
                return helper(grid, row + 1, col - 1); // col + 1 because cur == -1, goes to next col
            }
        }
        return -1;
    }
}