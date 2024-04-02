class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        if(n != t.size()) return false;
        unordered_map<int, int> map1, map2;
        for(int i = 0; i < n; ++i) {
            if(map1[s[i]] != map2[t[i]]) return false;
            map1[s[i]] = i+1;
            map2[t[i]] = i+1;
        }
        return true;
    }
};