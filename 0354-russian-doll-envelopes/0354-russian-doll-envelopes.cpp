class Solution {
public:
    static bool comp(vector<int> a, vector<int> b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0]< b[0];
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        int n = e.size();
        sort(e.begin(), e.end(), comp);
        // vector<int> dp(n+1, 1);
        // int ans = INT_MIN;
        // for(int i = 0; i < n; ++i) {
        //     for(int j = 0; j < i; ++j) {
        //         if(e[i][0] > e[j][0] && e[i][1] > e[j][1]) {
        //             dp[i] = max(dp[i], 1+dp[j]);
        //         }
        //     }
        //     ans = max(ans, dp[i]);
        // }
        
        vector<int> dp;
        for(auto it : e) {
            auto pos = lower_bound(dp.begin(), dp.end(), it[1]);
            if(pos == dp.end()) dp.push_back(it[1]);
            else *pos = it[1];
        }
        return dp.size();
    }
};