class Solution
{
public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges,
                              string_view labels)
    {
        vector<vector<int>> g(n);
        for (const auto &e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> seen(n);
        vector<int> count(26);
        vector<int> ans(n);
        function<void(int)> postOrder = [&](int i)
        {
            if (seen[i]++)
                return;
            int before = count[labels[i] - 'a'];
            for (int j : g[i])
                postOrder(j);
            ans[i] = ++count[labels[i] - 'a'] - before;
        };
        postOrder(0);
        return ans;
    }
};