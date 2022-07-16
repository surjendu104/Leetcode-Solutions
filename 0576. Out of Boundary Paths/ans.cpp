
/*Runtime: 6 ms, faster than 91.62% of C++ online submissions for Out of Boundary Paths.
Memory Usage: 6.6 MB, less than 78.30% of C++ online submissions for Out of Boundary Paths.*/
class Solution
{
public:
    int dp[51][51][51];
    long solve(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if (maxMove < 0)
            return 0;
        if (startColumn == n or startRow == m or startColumn < 0 or startRow < 0)
            return 1;

        if (dp[startRow][startColumn][maxMove] != -1)
            return dp[startRow][startColumn][maxMove];
        long up = solve(m, n, maxMove - 1, startRow - 1, startColumn);
        long down = solve(m, n, maxMove - 1, startRow + 1, startColumn);
        long left = solve(m, n, maxMove - 1, startRow, startColumn - 1);
        long right = solve(m, n, maxMove - 1, startRow, startColumn + 1);

        return dp[startRow][startColumn][maxMove] = (up + down + left + right) % 1000000007;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn) % 1000000007;
    }
};