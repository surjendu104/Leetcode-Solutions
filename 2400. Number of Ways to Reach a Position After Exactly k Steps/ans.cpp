class Solution {
public:
    long long f(int st,int e,int k,vector<vector<long long>>&dp){
        if(k==0 and st==e)return 1;
        if(k==0)return 0;
        
        long long ans=0;
        if(dp[st+1000][k]!=-1)return dp[st+1000][k];
        
        ans+=f(st-1,e,k-1,dp);
        ans+=f(st+1,e,k-1,dp);
        
        return dp[st+1000][k]=ans%1000000007;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<long long>>dp(3001,vector<long long>(1001,-1));
        long long ans=f(startPos,endPos,k,dp);
        return ans%1000000007;
    }
};