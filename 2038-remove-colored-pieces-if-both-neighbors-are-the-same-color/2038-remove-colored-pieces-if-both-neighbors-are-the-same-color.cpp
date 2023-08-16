class Solution {
public:
    bool winnerOfGame(string s) {
        int a = 0, b = 0;
        int i = 0, j = 0, n = s.size();
        
        if(n < 3)return false;
        
        while(j < n) {
            if(s[j] == 'A') {
                while(s[j] == 'A' && j < n)j++;
                a += (j-i) >= 3?(j-i-2):0;
                i = j;
            }else {
                while(s[j] == 'B' && j < n)j++;
                b += (j-i) >= 3?(j-i-2):0;
                i = j;
            }
        }
        return a > b ? true : false;
    }
};