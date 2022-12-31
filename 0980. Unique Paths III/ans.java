class Solution {
    public int uniquePathsIII(int[][] grid) {
        int start_i = 0, start_j = 0, step = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                }
                if (grid[i][j] != -1){

                    step++;
                }
            }
        }
        return dfs(grid, start_i, start_j, 1, step);
    }

    static int dfs(int grid[][], int i, int j, int step, int target_step) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == -1) {
            return 0;
        }
        if (grid[i][j] == 2) {
            return target_step == step ? 1 : 0;
        }
        grid[i][j] = -1;

        int paths = dfs(grid, i + 1, j, step + 1, target_step) + dfs(grid, i - 1, j, step + 1, target_step)
                + dfs(grid, i, j + 1, step + 1, target_step) + dfs(grid, i, j - 1, step + 1, target_step);
        grid[i][j] = 0;
        return paths;
    }
}