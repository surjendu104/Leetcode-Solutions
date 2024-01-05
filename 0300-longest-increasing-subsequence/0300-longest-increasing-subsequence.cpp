class Solution {
public:
    int f(vector<int> &nums, int idx, int prev, vector<vector<int>> &dp) {
        if(idx >= nums.size()) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        
        int p = -1;
        if(prev ==-1 || nums[prev] < nums[idx]) p = 1 + f(nums, idx+1, idx, dp);
        int q = f(nums, idx+1, prev, dp);
        return dp[idx][prev+1] = max(p, q);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return f(nums, 0, -1, dp);
    }
};