from typing import List


class Solution:
    def sharedRowCollumn(self, a: List[int], b: List[int]) -> bool:
        return a[0] == b[0] or a[1] == b[1]

    def dfs(self, stones: List[List[int]], adj: List[List[int]], visited: List[int], src: int):
        visited[src] = 1
        for adjacent in adj[src]:
            if(visited[adjacent] == 0):
                self.dfs(stones, adj, visited, adjacent)

    def removeStones(self, stones: List[List[int]]) -> int:
        adj = [[]*len(stones)]*len(stones)
        visited = [0]*len(stones)

        for i in range(0, len(stones)):
            for j in range(i+1, len(stones)):
                if(self.sharedRowCollumn(stones[i], stones[j])):
                    adj[i].append(j)
                    adj[j].append(i)

        countComponenet = 0
        for i in range(0, len(stones)):
            if(visited[i] == 0):
                countComponenet += 1
                self.dfs(stones, adj, visited, i)
        return len(stones)-countComponenet
