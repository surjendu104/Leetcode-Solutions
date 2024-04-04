class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int i = 0, ans = 0, cnt = 0;
        while(i < n) {
            if(s[i] == '(') cnt++;
            ans = max(ans, cnt);
            if(s[i] == ')') cnt--;
            i++;
        }
        return ans;
    }
};