/*Runtime: 5 ms, faster than 66.17% of C++ online submissions for Find and Replace Pattern.
Memory Usage: 7.9 MB, less than 92.07% of C++ online submissions for Find and Replace Pattern.*/
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;
        for (auto w : words)
            if (match(w, pattern)) // checking isomorphic string Lc205
                ans.push_back(w);

        return ans;
    }

    bool match(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int mp1[256]; // for mapping s to t
        int mp2[256]; // for mapping t to s

        for (int i = 0; i < 256; i++)
            mp1[i] = -1;
        for (int i = 0; i < 256; i++)
            mp2[i] = -1;

        for (int i = 0; i < s.size(); i++)
        {
            if (mp1[s[i]] != mp2[t[i]])
                return false;
            mp1[s[i]] = mp2[t[i]] = i;
        }
        return true;
    }
};