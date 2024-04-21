class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<int> vis(n, 0);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        q.push(source);
        vis[source] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(node == destination) return true;
            for(int adjNode : adj[node]) {
                if(!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
        return false;
    }
};