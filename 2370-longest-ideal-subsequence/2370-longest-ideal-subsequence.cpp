class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int curr = s[i] - 'a';
            // max to max allowed range of difference will be curr-k <= diff <= curr+k
            int left = max(0, curr - k);
            int right = min(25, curr + k);
            int longest = 0;
            for(int j = left; j <= right; ++j) {
                longest = max(longest, dp[j]);
            }
            dp[curr] = max(dp[curr], 1 + longest);
            ans = max(ans, dp[curr]);
        }
        return ans;
    }
};