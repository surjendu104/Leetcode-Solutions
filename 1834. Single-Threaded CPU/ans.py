import heapq
from typing import List


class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        for i, t in enumerate(tasks):
            t.append(i)
        tasks.sort(key=lambda t: t[0])

        ans, minHeap = [], []
        i, currTime = 0, tasks[0][0]

        while i < len(tasks) or minHeap:
            while i < len(tasks) and currTime >= tasks[i][0]:
                heapq.heappush(minHeap, [tasks[i][1], tasks[i][2]])
                i += 1
            if not minHeap:
                currTime = tasks[i][0]
            else:
                procTime, index = heapq.heappop(minHeap)
                currTime += procTime
                ans.append(index)
        return ans
