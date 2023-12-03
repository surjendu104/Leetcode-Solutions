class Solution {
public:
    int minPatches(vector<int>& c, int t) {
        int n = c.size();
        sort(c.begin(), c.end());
        long long maxi = 0;
        int i = 0, ans = 0;
        while(maxi < t) {
            if(i < n && c[i] <= maxi+1) {
                maxi += c[i];
                i++;
            } else {
                maxi += (maxi+1);
                ans++;
            }
        }
        return ans;
    }
};