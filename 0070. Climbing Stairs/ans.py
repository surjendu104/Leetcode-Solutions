class Solution:
    def helper(self, n: int, idx: int, dp: dict) -> int:
        if(idx > n):
            return 0
        if(idx == n):
            return 1
        if(dp[idx] != -1):
            return dp[idx]

        dp[idx+1] = self.helper(n, idx+1, dp)
        dp[idx+2] = self.helper(n, idx+2, dp)

        dp[idx] = dp[idx+1] + dp[idx+2]

        return dp[idx]

    def climbStairs(self, n: int) -> int:
        res = [-1]*100
        return self.helper(n, 0, res)


# Tabulation
class Solution:
    def climbStairs(self, n: int) -> int:
        if(n<=2): return n
        ans = dict()
        ans[0] = 1
        ans[1] = 2

        for i in range(2,n):
            ans[i] = ans[i-1] + ans[i-2]
        return ans[n-1]
