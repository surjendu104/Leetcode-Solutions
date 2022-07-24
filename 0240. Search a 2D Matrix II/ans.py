
'''Runtime: 169 ms, faster than 98.04% of Python3 online submissions for Search a 2D Matrix II.
Memory Usage: 20.5 MB, less than 40.22% of Python3 online submissions for Search a 2D Matrix II.'''


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        i, j = 0, len(matrix[0])-1
        while i < len(matrix) and j >= 0:
            if matrix[i][j] > target:
                j = j-1
            elif matrix[i][j] < target:
                i = i+1
            else:
                return True
        return False
