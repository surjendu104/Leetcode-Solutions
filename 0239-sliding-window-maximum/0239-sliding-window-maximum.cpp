class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        deque<int> dq;
        vector<int> ans;
        while(j < n) {
            if(!dq.empty() && dq.front() == j-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[j]) dq.pop_back();
            dq.push_back(j);
            if(j >= k-1) ans.push_back(nums[dq.front()]);
            j++;
        }
        return ans;
    }
};