from os import rename


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n, m = len(text1), len(text2)
        res = [[0 for i in range(m+1)]for j in range(n+1)]
        for i in range(n):
            for j in range(m):
                res[i][j] = (1+res[i-1][j-1]) if (text1[i] ==
                                                  text2[j]) else max(res[i-1][j], res[i][j-1])
        return res[n-1][m-1]
