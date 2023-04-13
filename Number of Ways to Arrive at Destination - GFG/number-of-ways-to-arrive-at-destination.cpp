//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define ll long long
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<ll, ll>> adj[n];
        for(auto it:roads) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<ll, ll>,vector<pair<ll, ll>>,greater<pair<ll, ll>>>pq;
        vector<ll> dist(n,INT_MAX),ways(n,0);
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int)(1e9 + 7);
        while(pq.size()) {
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]) {
                ll adjNode = it.first;
                ll edW = it.second;
                if(edW + dis < dist[adjNode]) {
                    dist[adjNode] = edW + dis;
                    pq.push({edW + dis, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(edW + dis == dist[adjNode]) {
                    ways[adjNode] = (ways[node] + ways[adjNode])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends