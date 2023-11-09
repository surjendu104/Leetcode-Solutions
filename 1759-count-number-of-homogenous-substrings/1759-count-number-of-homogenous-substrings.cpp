class Solution {
public:
    const int mod = 1000000007;
    int countHomogenous(string s) {
        int i = 0, j = 0;
        int n = s.size();
        if(n == 2 && s[0] != s[1]) return 2;
        int ans = 0;
        while(j < n) {
            while(j < n && s[i] == s[j]) j++;
            long long len = j-i;
            long long tot = (len *(len+1))/2;
            ans += tot % mod;
            i = j;
            j++;
        }
        // cout <<"dbg : " << i << " " << j << '\n';
        ans %= mod;
        if(n > 1 && s[n-1] != s[n-2]) ans++;
        return ans;
    }
};