class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for(char c : s) map[c]++;
        
        for(char c : t) {
            if(map[c] <= 0) return false;
            map[c]--;
        }
        
        for(auto it : map) {
            if(it.second > 0) return false;
        }
        return true;
    }
};