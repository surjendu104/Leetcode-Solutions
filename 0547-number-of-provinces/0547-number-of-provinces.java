class Solution {
    private static void dfs(int src, List<List<Integer>> g, boolean[] vis) {
        vis[src] = true;
        for(Integer node : g.get(src)) {
            if(!vis[node]) {
                dfs(node, g, vis);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        List<List<Integer>> g = new ArrayList<>();
        for(int i = 0; i < n; ++i)g.add(new ArrayList<>());
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(isConnected[i][j] == 1) {
                    g.get(i).add(j);
                    g.get(j).add(i);
                }
            }
        }
        boolean[] vis = new boolean[n];
        
        int components = 0;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                components++;
                dfs(i, g, vis);
            }
        }
        return components;
    }
}