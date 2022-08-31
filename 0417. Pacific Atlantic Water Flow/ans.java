class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int r=heights.length, c=heights[0].length;
        boolean[][] pac = new boolean[r][c];
        boolean[][] atl = new boolean[r][c];

        for (int i=0;i<c;i++){
            dfs(0,i,r,c,pac,heights[0][i],heights);
            dfs(r-1,i,r,c,atl,heights[r-1][i],heights);
        }
        for (int i=0;i<r;i++){
            dfs(i,0,r,c,pac,heights[i][0],heights);
            dfs(i,c-1,r,c,atl,heights[i][c-1],heights);
        }
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        for (int i=0;i<r;i++){
            for (int j=0; j<c;j++){
                if (pac[i][j] && atl[i][j]){
                    result.add(Arrays.asList(i,j));
                }
            }
        }
        return result;
    }
    private void dfs(int i, int j, int r, int c, boolean[][] visited, int prev, int[][] heights){
        if (i < 0 || i >= r || j < 0 || j>= c || visited[i][j] || prev > heights[i][j])
            return;
        visited[i][j]= true;
        dfs(i+1,j,r,c,visited,heights[i][j],heights);
        dfs(i-1,j,r,c,visited,heights[i][j],heights);
        dfs(i,j+1,r,c,visited,heights[i][j],heights);
        dfs(i,j-1,r,c,visited,heights[i][j],heights);
    }
    
}