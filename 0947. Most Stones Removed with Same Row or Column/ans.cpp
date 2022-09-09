#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool sharedRowCollumn(vector<int> &a, vector<int> &b)
    {
        return a[0] == b[0] || a[1] == b[1];
    }

    void dfs(vector<vector<int>> &stones, vector<int> adj[], vector<int> &visited, int src)
    {
        visited[src] = 1;
        for (int adjacent : adj[src])
        {
            if (visited[adjacent] == 0)
            {
                dfs(stones, adj, visited, adjacent);
            }
        }
    }
    int removeStones(vector<vector<int>> &stones)
    {
        vector<int> adj[stones.size()];
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = i + 1; j < stones.size(); j++)
            {
                if (sharedRowCollumn(stones[i], stones[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int countComponents = 0;
        vector<int> visited(stones.size(), 0);
        for (int i = 0; i < stones.size(); i++)
        {
            if (visited[i] == 0)
            {
                countComponents++;
                dfs(stones, adj, visited, i);
            }
        }
        return stones.size() - countComponents;
    }
};