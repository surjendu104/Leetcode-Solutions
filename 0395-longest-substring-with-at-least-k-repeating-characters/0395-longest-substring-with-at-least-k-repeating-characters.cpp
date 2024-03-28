class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> map;
        int uniq = 0;
        int len = 0;
        while(j < n) {
            map[s[j]]++;
            if(map[s[j]] == k) uniq++;
            if(uniq == map.size()) len = max(len, j - i + 1);
            j++;
            
            if(j == n) {
                map.clear();
                i++;
                j = i;
                uniq = 0;
            }
        }
        return len;
    }
};