class Solution {
public:
    string reverseWords(string s) {
        string ans,x;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                x+=s[i];
            }
            else{
                reverse(x.begin(),x.end());
                ans+=(x+' ');
                x.clear();
            }
        }
        reverse(x.begin(),x.end());
        ans+=x;
        return ans;
    }
};