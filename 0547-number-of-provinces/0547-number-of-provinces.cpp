class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        
        for(int adjacentNode : adj[node]) {
            if(!vis[adjacentNode])dfs(adjacentNode, adj, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(isConnected[i][j] == 1)adj[i].push_back(j);
            }
        }
        
        vector<int> vis(n, 0);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                ans++;
            }
        }
        return ans;
    }
};