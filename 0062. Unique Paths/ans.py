class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0]*(n+1)]*(m+1)
        dp[0][0] = 1
        for i in range(0, m):
            for j in range(0, n):
                if i == 0 and j == 0:
                    continue
                down, right = 0, 0
                if(i > 0):
                    down = dp[i-1][j]
                if(j > 0):
                    right = dp[i][j-1]
                dp[i][j] = right+down
        return dp[m-1][n-1]
