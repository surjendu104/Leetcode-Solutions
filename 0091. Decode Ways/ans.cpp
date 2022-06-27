
//Recursion ::::: TLE
class Solution {
    int f(string s,int i){
        int n=s.size();
        if(i==n) return 1;
        if(s[i]=='0')return 0;//for one digit generation checking if one digit is 0 or not        
        int ans =f(s,i+1); //Generating one digit

        if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))){
            ans+=f(s,i+2); //two digit
        }
        return ans;
    }
public:
    int numDecodings(string s) {
        if(s.size()==0)return 0;
        return f(s,0);
    }
};


//Memoisation ::::: Accepted

/*Runtime: 3 ms, faster than 59.16% of C++ online submissions for Decode Ways.
Memory Usage: 7.6 MB, less than 11.24% of C++ online submissions for Decode Ways.*/
class Solution {
    int f(string s,int i,vector<int>&dp){
        int n=s.size();
        if(i==n) dp[i] =1;
        if(s[i]=='0')dp[i] =0;//for one digit generation checking if one digit is 0 or not        
        if(dp[i]!=-1)return dp[i];
        int ans =f(s,i+1,dp); //Generating one digit

        if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))){
            ans+=f(s,i+2,dp); //two digit
        }
        return dp[i] = ans;
    }
public:
    int numDecodings(string s) {
        if(s.size()==0)return 0;
        vector<int>dp(s.size()+1,-1);
        return f(s,0,dp);
    }
};