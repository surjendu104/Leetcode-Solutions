class Solution {
public:
    bool check(char x) {
        return x=='a'|| x=='e'|| x=='i'|| x=='o'|| x=='u';
    }
    int maxVowels(string s, int k) {
        int ans = 0, cur  = 0;
        for(int i = 0; i<s.size(); i++) {
            cur += check(s[i]);
            if(i-k >= 0)cur-=check(s[i-k]);
            ans = max(ans, cur);
        }
        return ans;
    }
};