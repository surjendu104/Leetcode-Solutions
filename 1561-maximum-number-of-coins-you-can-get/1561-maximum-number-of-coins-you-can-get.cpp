class Solution {
public:
    int maxCoins(vector<int>& p) {
        int n = p.size();
        int i = 0, j = n-2;
        sort(p.begin(), p.end());
        
        int ans = 0;
        while(i < j) {
            ans += p[j];
            j -= 2;
            i++;
        }
        return ans;
    }
};