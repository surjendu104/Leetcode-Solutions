class Solution {
public:
    string solve(int idx, vector<string> &nums, string str, int n, set<string> st) {
        // base case
        if(idx >= n) {
            // cout << "!! " << str << '\n';
            if(st.count(str) == 0) return str;
            return "";
        }
        // not take
        string result = solve(idx+1, nums, str+'0', n, st);
        if(result.size()) return result;
        result = solve(idx+1, nums, str+'1', n, st);
        if(result.size()) return result;
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        set<string> st(nums.begin(), nums.end());
        string str = "";
        int idx = 0;
        string ans = solve(idx, nums, str, n, st);
        return ans;
    }
};