class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.size();
        vector<string> v;
        
        string tmp = "";
        for(int i = 0; i < n; ++i) {
            tmp+=s[i];
            if(s[i+1]==' ' && i+1 < n) {
                v.push_back(tmp);
                tmp = "";
                i++;
            }
        }
        v.push_back(tmp);
        if(v.size()!=pattern.size())return false;
        
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        
        for(int i = 0; i<pattern.size(); ++i) {
            if(mp1.find(pattern[i])==mp1.end())mp1[pattern[i]] = v[i];
            else if(mp1[pattern[i]]!=v[i])return false;
        }
        for(int i = 0; i<v.size();i++) {
            if(mp2.find(v[i])==mp2.end())mp2[v[i]] = pattern[i];
            else if(mp2[v[i]]!=pattern[i])return false;
        }
        // if(mp1.size()==mp2.size())return false;
        return true;
    }
};