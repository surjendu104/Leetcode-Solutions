
//RECURSION(TLE)
class Solution {
    public int solve(int n,int k,int target){
        if(target==0 || n==0)return 1;

        if((n>0 && target==0) || (n==0 && target>0))return 0;

        long ans=0;

        for(int i=k;i>=1;i--){
            if(target-i>=0){
                ans+=solve(n-1,k,target-i);
            }
            // else ans+=solve(n-1,k,target-i,dp);
            ans%=1000000009;
        }
        return (int)ans;
    }
    public int numRollsToTarget(int n, int k, int target) {

        // int[][] dp = new int[n+1][target+1];
        return solve(n,k,target);
    }
}