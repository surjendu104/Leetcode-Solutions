class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, int> map1, map2;
        for(char c = 'a'; c <= 'z'; ++c) map1[c] = INT_MAX;
        for(char c = 'a'; c <= 'z'; ++c) map2[c] = INT_MIN;
        for(int i = 0; i < n; ++i) {
            map1[s[i]] = min(map1[s[i]], i);
            map2[s[i]] = max(map2[s[i]], i);
        }
        int ans = 0;
        
        for(auto it : map1) {
            char c = it.first;
            if(map1[c] == INT_MAX || map2[c] == INT_MIN) continue;
            set<char> st;
            for(int j = map1[c] + 1; map2.find(c) != map2.end() && j < map2[c]; ++j) {
                st.insert(s[j]);
            }
            ans += st.size();
        }
        return ans;
    }
};