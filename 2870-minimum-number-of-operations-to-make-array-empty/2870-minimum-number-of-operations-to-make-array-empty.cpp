class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i : nums) map[i]++;
        int ans = 0;
        for(auto it : map) {
            int x = it.second;
            if(x == 1) return -1;
            if(x % 3 == 0) ans += x/3;
            else if(x % 3 == 1 || x%3 == 2) ans += (x/3) + 1;
            else if(x % 2 == 0) ans += (x/2);
        }
        return ans;
    }
};