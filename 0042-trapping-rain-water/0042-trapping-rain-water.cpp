class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> pre(n, 0), suff(n, 0);
        pre[0] = h[0];
        suff[n-1] = h[n-1];
        for(int i = 1; i < n; ++i) {
            pre[i] = max(pre[i-1], h[i]);
            suff[n-1-i] = max(suff[n-i], h[n-1-i]);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += (min(pre[i], suff[i]) - h[i]);
        }
        return ans;
    }
};