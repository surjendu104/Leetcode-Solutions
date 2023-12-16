class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        unordered_map<char, int> map;
        for (char c : p) map[c]++;

        vector<int> ans;
        int i = 0, j = 0;
        unordered_map<char, int> map2;

        while (j < n) {
            if (map.find(s[j]) != map.end()) {
                map2[s[j]]++;
                while (map2[s[j]] > map[s[j]]) {
                    map2[s[i]]--;
                    if (map2[s[i]] == 0) map2.erase(s[i]);
                    i++;
                }

                if (j - i + 1 == m) {
                    ans.push_back(i);
                }
            } else {
                map2.clear();
                i = j + 1;
            }
            // cout << i << ' ' << j << '\n';
            j++;
        }
        return ans;
    }
};
