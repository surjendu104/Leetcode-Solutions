class Solution {

    public void dfs(int u, int[] vis, int[] dis, int[] edges) {
        vis[u] = 1;
        int v = edges[u];
        if (v != -1 && vis[v] == 0) {
            dis[v] = dis[u] + 1;
            dfs(v, vis, dis, edges);
        }
    }

    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int n = edges.length;
        int[] dis1 = new int[n];
        int[] dis2 = new int[n];
        Arrays.fill(dis1, Integer.MAX_VALUE);
        Arrays.fill(dis2, Integer.MAX_VALUE);

        int[] vis1 = new int[n];
        int[] vis2 = new int[n];

        dis1[node1] = 0;
        dis2[node2] = 0;

        dfs(node1, vis1, dis1, edges);
        dfs(node2, vis2, dis2, edges);

        int ans = -1, mini = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            if (Math.max(dis1[i], dis2[i]) < mini) {
                mini = Math.max(dis1[i], dis2[i]);
                ans = i;
            }
        }
        return ans;
    }
}