class Solution {
public:
    bool dfs(int node, vector<vector<int>>&adj, vector<bool>&vis, vector<bool> &inStack) {
        if(inStack[node])return true;
        if(vis[node])return false;
        
        vis[node] = true;
        inStack[node] = true;
        for(auto it : adj[node]) {
            if(dfs(it,adj, vis,inStack)) {
                return true;
            }
        }
        inStack[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < n; i++) {
            for(auto node : graph[i]) {
                adj[i].push_back(node);
            }
        }
        
        vector<bool> vis(n), inStack(n);
        
        for(int i = 0; i < n; ++i) {
            dfs(i, adj, vis, inStack);
        }
        
        vector<int> safeNodes;
        for(int i = 0; i < n; i++) {
            if(!inStack[i])safeNodes.push_back(i);
        }
        return safeNodes;
    }
};