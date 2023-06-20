class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n);
        vector<int> ans(n);
        
        pre[0] = nums[0];
        for(int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + nums[i];
        }
        for(int i = 0; i < n; i++) {
            if(i+k < n && i-k >=0) {
                ans[i] = (pre[i+k]-pre[i-k] + nums[i-k]) / (2*k +1);
            }else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};