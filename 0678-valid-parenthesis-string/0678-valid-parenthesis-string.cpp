class Solution {
public:
    bool checkValidString(string s) {
        int lmin = 0, lmax = 0;
        for(char c : s) {
            if(c == '(') {lmin++; lmax++;}
            else if(c == ')') {lmin--; lmax--;}
            else {lmin--; lmax++;}
            if(lmax < 0) return false;
            if(lmin < 0) lmin = 0;
        }
        return lmin == 0;
    }
};