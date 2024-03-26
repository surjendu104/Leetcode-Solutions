class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int ans = -1;
        int i = 1;
        while(ans < 0) {
            if(st.count(i) == 0) ans = i;
            i++;
        }
        return ans;
    }
};