class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = 0;
        for(int i = 0; i < word.size(); ++i) {
            idx++;
            if(word[i] == ch) break;
        }
        cout << "@ " <<word.size() << ' ' <<  idx << '\n';
        if(idx == word.size()) {
            if(word[word.size()-1] == ch){reverse(word.begin(), word.end());} 
            return word;
        } 
        string s = word.substr(0, idx);
        reverse(s.begin(), s.end());
        for(int i = idx; i < word.size(); ++i) s += word[i];
        return s;
    }
};