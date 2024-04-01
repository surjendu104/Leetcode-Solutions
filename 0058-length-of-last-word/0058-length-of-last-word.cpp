class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int k = s.size() - 1;
        while(k >= 0 && s[k] == ' ') --k;
        for(int i = k; i >= 0 && s[i] != ' '; --i) {
            len++;
        }
        return len;
    }
};