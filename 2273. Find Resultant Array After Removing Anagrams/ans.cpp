#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string p, string q)
    {
        vector<int> cnt(26);
        int res = 0;
        for (auto i : p)
            cnt[i - 'a']++;
        for (auto i : q)
            cnt[i - 'a']--;
        for (auto i : cnt)
            if (i != 0)
                return false;
        return true;
    }
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> ans;
        for (int i = 0; i < words.size();)
        {
            int j = i + 1;
            while (j < words.size() and isAnagram(words[i], words[j]))
                j++;

            ans.push_back(words[i]);
            i = j;
        }
        return ans;
    }
};