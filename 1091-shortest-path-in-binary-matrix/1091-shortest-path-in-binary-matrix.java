class Solution {
    private void grow(int[][] grid, int[][] dist, int r, int c) {
        int m = grid.length, n = grid[0].length;
        int d0 = dist[r][c];
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0)
                    continue;
                int x = r + i;
                int y = c + j;
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 1)
                        continue;
                    int d1 = dist[x][y];
                    if (d1 < d0-1) { // get a smaller value from a neighbor; then re-start the process.
                        dist[r][c] = d1+1;
                        grow(grid, dist, r, c); // TODO some optimization to avoid stack overflow
                        return;
                    } else if (d1 > d0+1) { // give a smaller value to a neighbor
                        dist[x][y] = d0+1;
                        grow(grid, dist, x, y);
                    }
                }
            }
        }
    }

    public int shortestPathBinaryMatrix(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] dist = new int[m][n]; // dist[i][j]: distance of the cell (i,j) to (0,0)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = Integer.MAX_VALUE;
            }
        }
        dist[0][0] = 1;
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return -1;
        grow(grid, dist, 0, 0);
        return (dist[m-1][n-1] != Integer.MAX_VALUE ? dist[m-1][n-1] : -1);
    }
}