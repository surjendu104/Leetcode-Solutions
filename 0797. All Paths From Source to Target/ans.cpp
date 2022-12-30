class Solution
{
public:
    vector<vector<int>> ans;
    void dfs(int i, vector<int> &curr, vector<vector<int>> &graph)
    {
        if (i == graph.size() - 1)
        {
            ans.push_back(curr);
            return;
        }
        for (int j : graph[i])
        {
            curr.push_back(j);
            dfs(j, curr, graph);
            curr.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<int> curr;
        curr.push_back(0);
        dfs(0, curr, graph);
        return ans;
    }
};