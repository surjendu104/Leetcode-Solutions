class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<bool> check(1001, false);
        map<int, int> map;
        for(int i : arr) map[i]++;
        for(auto &[u, v] : map) {
            if(check[v]) return false;
            check[v] = true;
        }
        return true;
    }
};