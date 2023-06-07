class Solution {
public:
    string intToBinary(int n) {
        string ans = "";
        while(n>0) {
            ans+=to_string(n%2);
            n/=2;
        }
        
        return ans;
    }
    int minFlips(int ah, int bh, int ch) {
        string a = intToBinary(ah);
        string b = intToBinary(bh);
        string c = intToBinary(ch);
        
        int size = max({a.size(), b.size(), c.size()});
        
        if(size != a.size()) {
            int x = a.size();
            for(int i = 0; i < size-x; ++i)a+='0';
        }
        if(size != b.size()) {
            int x = b.size();
            for(int i = 0; i < size-x; ++i)b+='0';
        }
        if(size != c.size()) {
            int x = c.size();
            for(int i = 0; i < size-x; ++i)c+='0';
        }
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(c.begin(), c.end());
        cout<<a<<' '<<b<<' '<<c<<endl;
        int flip = 0;
        for(int i = 0; i < c.size(); ++i) {
            if(c[i]=='1') {
                if(a[i]=='0' && b[i] == '0') {
                    flip++;
                    // cout<<"dbg1\n";
                }
            }else if(c[i]=='0') {
                if(a[i]=='1' && b[i]=='1'){
                    flip+=2;
                    // cout<<"dbg2\n";
                }
                else if(a[i]=='1' || b[i]=='1'){
                    // cout<<"dbg3\n";
                    flip++;
                }
            }
        }
        return flip;
    }
};