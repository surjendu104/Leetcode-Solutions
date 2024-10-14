class Solution {
public:
    vector<string> splitSentance(string &s) {
        vector<string> words;
        string word = "";
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) words.push_back(word);
        return words;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> first = splitSentance(sentence1);
        vector<string> second = splitSentance(sentence2);
        
        if(first.size() < second.size()) swap(first, second);
        int n1 = first.size(), n2 = second.size();
        int start = 0, end = 0;
        while(start < n2 && first[start] == second[start]) start++;
        while (end < n2 && first[n1 - end - 1] == second[n2 - end - 1]) end++;
        return start+end >= n2;
    }
};