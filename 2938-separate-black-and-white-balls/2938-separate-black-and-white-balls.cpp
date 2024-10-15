class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long ans = 0;
        vector<long long> suff(n, 0);
        suff[n-1] = (s[n-1] == '0') ? 1 : 0;
        for(int i = n-2; i >= 0; --i) {
            suff[i] = suff[i+1];
            if(s[i] == '0') suff[i]++;
        }
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1') ans += suff[i];
        }
        return ans;
    }
};
// 1 0 1 0 0 0 1
// 