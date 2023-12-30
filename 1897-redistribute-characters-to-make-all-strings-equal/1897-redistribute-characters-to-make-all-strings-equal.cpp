class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        map<char, int> map;
        for(string s : words) {
            for(char c : s) map[c]++;
        }
        
        for(auto it : map) {
            int x = it.second;
            if(x % n != 0) return false;
        }
        return true;
    }
};