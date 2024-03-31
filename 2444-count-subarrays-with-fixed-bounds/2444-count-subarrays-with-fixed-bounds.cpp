#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll ans = 0;
        int n = nums.size();
        int left = -1, right = -1, exclude = -1;
        for(int i = 0; i < n; ++i) {
            int x = nums[i];
            if(!(minK <= x && x <= maxK)) exclude = i;
            if(x == minK) left = i;
            if(x == maxK) right = i;
            ans += max(min(left, right) - exclude, 0);
        }
        return ans;
    }
};