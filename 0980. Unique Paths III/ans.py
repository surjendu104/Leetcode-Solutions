from typing import List


class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        t_step, start_i, start_j = 0, 0, 0
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                if grid[i][j] == 1:
                    start_i, start_j = i, j
                if grid[i][j] != -1:
                    t_step += 1
        return self.dfs(grid, start_i, start_j, 1, t_step)

    def dfs(self, grid: List[List[int]], i: int, j: int, steps: int, target_step: int) -> int:
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == -1:
            return 0
        if grid[i][j] == 2:
            if(steps == target_step):
                return 1
            return 0
        grid[i][j] = -1
        path = self.dfs(grid, i, j-1, steps+1, target_step)+self.dfs(grid, i-1, j, steps+1, target_step) + \
            self.dfs(grid, i, j+1, steps+1, target_step) + \
            self.dfs(grid, i+1, j, steps+1, target_step)
        grid[i][j] = 0
        return path
