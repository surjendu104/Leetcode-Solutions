#define ll long long

class Solution {
    ll mod = 1e9 + 7;
public:
    ll solve(vector<int>& nums,int idx,ll sum,int k,vector<vector<int>> &dp) {
        if(sum>=k)return 0;
        if(idx==nums.size())return sum<k;
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        ll ans = (solve(nums,idx+1,sum+nums[idx],k,dp)%mod) + (solve(nums,idx+1,sum,k,dp)%mod);
        return dp[idx][sum] = ans;
    }
    int countPartitions(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(),vector<int>(k,-1));
        ll tot = 1,sum = 0;
        for(int i:nums) {
            sum+=i;
            tot=(tot*2LL)%mod;
        }
        if(sum<2*k)return 0;
        ll cnt = solve(nums,0,0,k,dp)%mod;
        cnt = (cnt*2LL)%mod;
        ll res = (tot-cnt+mod)%mod;
        return res;
    }
};