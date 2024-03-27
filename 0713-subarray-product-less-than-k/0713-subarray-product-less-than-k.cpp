class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long p = 1;
        int ans = 0;
        while(j < n) {
            p *= nums[j];
            while(i <= j && p >= k) {
                p /= nums[i];
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
};