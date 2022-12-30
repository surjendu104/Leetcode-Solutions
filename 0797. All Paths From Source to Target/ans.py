class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        nodes = len(graph)
        result = []

        def dfs(i, curr):
            if i == nodes-1:
                result.append(curr[:])
                return
            for j in graph[i]:
                dfs(j, curr+[j])
        dfs(0, [0])
        return result
