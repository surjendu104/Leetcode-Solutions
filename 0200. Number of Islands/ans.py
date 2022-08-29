class Solution:
    def dfs(self, mat: List[List[str]], row, col) -> None:
        n, m = len(mat), len(mat[0])

        if row < 0 or col < 0 or row >= n or col >= m or mat[row][col] != "1":
            return
        mat[row][col] = "0"
        # dfs
        self.dfs(mat, row+1, col)
        self.dfs(mat, row-1, col)
        self.dfs(mat, row, col+1)
        self.dfs(mat, row, col-1)

    def numIslands(self, grid: List[List[str]]) -> int:
        n, m = len(grid), len(grid[0])

        ans = 0
        for i in range(0, n):
            for j in range(0, m):
                if grid[i][j] == "1":
                    self.dfs(grid, i, j)
                    ans += 1
        return ans
