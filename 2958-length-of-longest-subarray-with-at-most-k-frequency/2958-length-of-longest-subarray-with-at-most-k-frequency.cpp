class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            map[nums[j]]++;
            
            while (i <= j && map[nums[j]] > k) {
                map[nums[i]]--;
                if (map[nums[i]] == 0) {
                    map.erase(nums[i]);
                }
                i++;
            }

            ans = max(ans, j - i + 1);

            j++;
        }

        return ans;
    }
};