class Solution
{
public:
    void dfs(vector<vector<char>> &mat, int row, int col)
    {
        int n = mat.size();
        int m = mat[0].size();

        // Check for row or collumn index out of bound error
        if (row < 0 or col < 0 or row >= n or col >= m or mat[row][col] != '1')
            return;

        // Mark the cell as visited by making "0"
        mat[row][col] = '0';

        // dfs in every direction
        dfs(mat, row + 1, col);
        dfs(mat, row - 1, col);
        dfs(mat, row, col + 1);
        dfs(mat, row, col - 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if (n == 0)
            return 0;
        int ans = 0;

        // Travese through each cell.Whenever get "1" run the dfs
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};