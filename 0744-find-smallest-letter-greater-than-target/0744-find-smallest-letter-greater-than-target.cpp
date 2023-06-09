class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> tmp(letters.begin(), letters.end());
        sort(letters.begin(), letters.end());
        int pos = upper_bound(letters.begin(), letters.end(), target)-letters.begin();
        
        if(pos>=letters.size())return tmp[0];
        return letters[pos];
    }
};