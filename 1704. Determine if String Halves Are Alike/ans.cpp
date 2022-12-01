class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0;
        for(int i=0;i<s.size()/2;i++) {
            if(st.count(s[i])!=0)count++;
        }
        for(int i=s.size()/2;i<s.size();i++) {
            if(st.count(s[i])!=0)count--;
        }
        return (count==0);
    }
};