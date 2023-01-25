import java.util.List;

class Solution {
    public void dfs(int u, List<Integer>[] g, int[] vis) {
        vis[u] = 1;
        for (int i : g[u]) {
            if (vis[i] == 0) {
                dfs(i, g, vis);
            }
        }
    }

    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1)
            return -1;

        int[] vis = new int[n];
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        for (int[] i : connections) {
            adj[i[0]].add(i[1]);
            adj[i[1]].add(i[0]);
        }

        int component = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, adj, vis);
                component++;
            }
        }
        return component - 1;
    }
}