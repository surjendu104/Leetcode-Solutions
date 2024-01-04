class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26);
        for(char c : sentence) arr[c-'a']++;
        for(int i : arr) {
            if(i == 0) return false;
        }
        return true;
    }
};