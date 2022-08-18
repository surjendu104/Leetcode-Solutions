class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        s = 0
        for i in range(0, n):
            s += mat[i][i]
            j = n-1
        for i in range(0, n):
            s += mat[i][j]
            j = j-1
        if n % 2 != 0:
            return s-mat[n//2][n//2]
        else:
            return s
