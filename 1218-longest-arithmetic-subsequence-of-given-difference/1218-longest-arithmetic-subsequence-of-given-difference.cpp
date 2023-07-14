class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = INT_MIN;
        unordered_map<int, int> map;
        for(int i = 0; i < arr.size(); ++i) {
            int cur = arr[i];
            if(map.find(cur-difference) != map.end()) {
                map[cur] = map[cur-difference] + 1;
            }else {
                map[cur] = 1;
            }
            ans = max(ans, map[cur]);
        }
        return ans;
    }
};