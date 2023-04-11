class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        int i = 0,n = s.size();
        
        while(i<n) {
            if(s[i]!='*')ans+=s[i];
            else ans.pop_back();
            i++;
        }
        return ans;
    }
};