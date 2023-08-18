class Solution {
public:
    bool comp(vector<int> a, vector<int> b) {
        return a.size() < b.size();
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> g[n];
        for(int i = 0; i < roads.size(); ++i) {
            g[roads[i][0]].push_back(roads[i][1]);
            g[roads[i][1]].push_back(roads[i][0]);
        }
        
        map<int, int> map;
        for(int i = 0; i < n; ++i) {
            map[i] = g[i].size();
        }
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < g[i].size(); j++) {
                dp[i][g[i][j]] = true;
            } 
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; ++j)cout<<dp[i][j]<<' ';
            cout<<endl;
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                int x = map[i]+map[j];
                if(dp[i][j])x--;
                ans = max(x, ans);
            }
        }
        return ans;
    }
};