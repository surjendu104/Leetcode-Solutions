import java.util.ArrayList;
import java.util.List;

class Solution {
    int dfs(ArrayList<Integer>[] g,List<Boolean>hasApple,int curr,int parent) {
        int time = 0;
        
        for(int child:g[curr]) {
            if(child==parent)continue;
            int childTime = dfs(g,hasApple,child,curr);

            if(childTime>0 or hasApple.get(child)) {
                time += 2+childTime;
            }
        }

        return time;
    }

    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }

        for (int[] node : edges) {
            adj[node[0]].add(node[1]);
            adj[node[1]].add(node[0]);
        }

        return dfs(adj, hasApple, 0, -1);
    }
}