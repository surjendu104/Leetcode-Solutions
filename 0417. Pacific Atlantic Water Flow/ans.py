class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m,n = len(heights),len(heights[0])
        pac, atl = set(),set()
        
        def dfs(r,c,visited,prevH):
            if (((r,c) in visited) or (not(m>r>=0 and n>c>=0)) or (heights[r][c]<prevH)):
                return
            
            visited.add((r,c))
            dfs(r + 1,c,visited,heights[r][c])
            dfs(r - 1,c,visited,heights[r][c])
            dfs(r,c + 1,visited,heights[r][c])
            dfs(r,c - 1,visited,heights[r][c])
        
        # first and last row -> for each cell do dfs
        for c in range(n):
            dfs(0, c, pac, heights[0][c])
            dfs(m-1, c, atl, heights[m-1][c])
            
        # first and last col -> for each cell do dfs
        for r in range(m):
            dfs(r, 0, pac, heights[r][0])
            dfs(r, n-1, atl, heights[r][n-1])

        # return intersection 
        return pac&atl
        # return pac.intersection(atl)