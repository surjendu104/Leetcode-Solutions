class Solution
{
public:
    int dfs(vector<vector<int>> &adj, vector<bool> &hasApple, int curr, int parent)
    {
        int time = 0;

        for (int child : adj[curr])
        {
            if (child == parent)
                continue;
            int childTime = dfs(adj, hasApple, child, curr);

            if (childTime > 0 || hasApple[child])
            {
                time += 2 + childTime;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> adj(n);
        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return dfs(adj, hasApple, 0, -1);
    }
};