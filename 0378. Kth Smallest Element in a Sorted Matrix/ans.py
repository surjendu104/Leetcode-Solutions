from heapq import heappop, heappush
from itertools import chain


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        a = []
        for i in chain(*matrix):
            heappush(a, -i)
            if(len(a) > k):
                heappop(a)
        return -a[0]


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        i, j = matrix[0][0], matrix[n-1][n-1]
        while(i < j):
            mid = i+(j-i)//2
            temp, c = n-1, 0
            for i in range(0, n):
                while temp >= 0 and matrix[i][temp] > mid:
                    temp = temp-1
                c = c+temp+1
            if(c < k):
                i = mid+1
            else:
                j = mid
        return i
