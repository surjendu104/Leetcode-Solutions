class Solution {
public:
    int atMost(vector<int>&nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;
        unordered_map<int, int> map;
        while(j < n) {
            map[nums[j]]++;
            while(map.size() > k) {
                map[nums[i]]--;
                if(map[nums[i]] == 0) map.erase(nums[i]);
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};