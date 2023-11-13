class Solution {
public:
    bool isVowel(char c) {
        // set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        // return st.count(c);
        return c == 'a' || c == 'e' || c == 'i'|| c == 'o'|| c == 'u'|| c == 'A'|| c == 'E'|| c == 'I'|| c == 'O'|| c == 'U';
    }
    string sortVowels(string s) {
        vector<char> vow;
        for(char c : s) {
            if(isVowel(c)) vow.push_back(c);
        }
        sort(begin(vow), end(vow));
        int idx = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(isVowel(s[i])) {
                s[i] = vow[idx];
                idx++;
            }
        }
        return s;
    }
};