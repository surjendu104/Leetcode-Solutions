//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        // code here
        string v = s;
        for(int i = 0;i<n;i++) {
            if(s[i]=='1') {
                int tmp = i;
                int cnt = x;
                int j = i+1;
                while(cnt--) {
                    if(s[j]=='0' && j<n) {
                        s[j]='1';
                        j++;
                        i++;
                    }
                }
                cnt = x,j = tmp-1;
                while(cnt--) {
                    if(s[j]=='0' && j>=0) {
                        s[j]='1';
                        j--;
                    }
                }
            }
            
            else if(s[i]=='0')continue;
        }
        // cout<<s<<endl;
        for(char c : s) {
            if(c=='0')return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends