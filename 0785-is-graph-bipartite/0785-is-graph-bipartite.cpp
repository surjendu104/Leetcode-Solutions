class Solution {
public:
    bool dfs(vector<vector<int>> &adj, int node,vector<int> &colors,int col) {
        colors[node] = col;
        
        for(auto it : adj[node]) {
            if(colors[it]==-1){
                if(dfs(adj, it, colors, !col)==false)return false;
            }
            else if(colors[it] == col)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        int col = 0;
        vector<int> colors(n, -1);
        
        for (int i = 0; i < n; ++i) {
            if(colors[i] == -1){
                if(dfs(graph, i,colors,0) == false)return false;
            }
        }
        return true;
    }
};