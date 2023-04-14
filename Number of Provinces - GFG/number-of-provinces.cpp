//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] == rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] == rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int getAns(int n){
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            if(parent[i] = i)cnt++;
        }
        return cnt;
    }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DisjointSet ds(V);
        for(int i = 0; i<V;i++) {
            for(int j = 0;j<V;j++) {
                if(adj[i][j]==1) {
                    ds.unionByRank(i,j);
                }
            } 
        }
        int cnt = 0;
        for(int i = 0; i<V; i++) {
            if(ds.findParent(i) == i)cnt++;
        }
        return cnt;
        
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends