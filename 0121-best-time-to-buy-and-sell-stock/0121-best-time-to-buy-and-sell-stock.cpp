class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = INT_MAX;
        for(int i : prices) {
            mini = min(i,mini);
            ans = max(ans, i-mini);
        }
        return ans;
    }
};