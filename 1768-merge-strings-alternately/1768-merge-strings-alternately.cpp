class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0,j = 0, k = 0;
        int n = word1.size(), m = word2.size();
        string ans = "";
        bool ok = false;
        for(int x = 0;x<n+m;x++) {
            if(i==n || j==m) {
                break;
            }
            if(!ok) {
                ans+=word1[i];
                i++;
                ok = true;
            }else if(ok) {
                ans+=word2[j];
                j++;ok = false;
            }
            
        }
        // cout<<i<<' '<<j<<' '<<ans<<endl;
        while(i<n) {
            ans+=word1[i];
            i++;
        }
        while(j<m) {
            ans+=word2[j];
            j++;
        }
        return ans;
    }
};