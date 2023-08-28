class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int> dp(n+1, 0);
        for(int i : nums) dp[i]+=i;
        
        for(int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i-1], dp[i]+dp[i-2]);
        }
        return dp[n];
    }
};