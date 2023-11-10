class Solution {
public:
    void dfs(int node, int prev, unordered_map<int, vector<int>> &adj, vector<int> &ans) {
        ans.push_back(node);
        for(auto ele : adj[node]) {
            if(ele != prev) dfs(ele, node, adj, ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        vector<int> ans;
        
        for(auto it : adjacentPairs) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int start = -1;
        
        for(auto it : adj) {
            if(it.second.size() == 1) {
                start = it.first;
                break;
            }
        }
        dfs(start, -1, adj, ans);
        return ans;
    }
};