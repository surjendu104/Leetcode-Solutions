class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &visited, string &current, string &find, double value) {
        if (current == find)
            return value;

        visited.insert(current);

        for (auto &p: adj[current]) {
            if (visited.find(p.first) == visited.end()) {
                double n = dfs(adj, visited, p.first, find, value*p.second);
                if (n != -1.0)
                    return n;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < equations.size(); ++i) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }

        unordered_set<string> visited;
        vector<double> answer;
        for (auto &q: queries) {
            visited = {};
            if (q[0] == q[1] and adj.find(q[0]) == adj.end())
                answer.push_back(-1.0);
            else
                answer.push_back(dfs(adj, visited, q[0], q[1], 1));
        }

        return answer;
    }
};