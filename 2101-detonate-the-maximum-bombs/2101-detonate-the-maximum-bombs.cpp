#define ll long long
class Solution {
public:
    void dfs(int src, vector<int> adj[], vector<int> &vis) {
        vis[src] = 1;
        for(int i : adj[src]) {
            if(!vis[i])dfs(i, adj,vis);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];
        
        for(int i = 0; i < n; i++) {
            ll x1 = bombs[i][0];
            ll y1 = bombs[i][1];
            ll r = bombs[i][2];
            
            for(int j = 0; j < n; j++) {
                if(i!=j) {
                    ll x2 = bombs[j][0];
                    ll y2 = bombs[j][1];

                    ll dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                    if(dist <= r*r) {
                        adj[i].push_back(j);
                    }
                }
                
            }
        }
        
        
        int ans = 0;
        for(int i = 0; i < n ;++i) {
            vector<int> vis(n,0);
            
            dfs(i, adj, vis);
            
            int cnt = 0;
            for(int i = 0; i < n; ++i) if(vis[i] == 1)cnt++;
            
            ans = max(ans,cnt);
        }
        return ans;
    }
};