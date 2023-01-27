class Solution
{
public:
    int helper(set<string> &st, int start, string &s)
    {
        if (start >= s.size())
            return 0;

        string stringTillIndex = "";
        int maxi = INT_MIN;

        for (int idx = start; idx < s.size(); idx++)
        {
            stringTillIndex.push_back(s[idx]);
            if (!st.count(stringTillIndex))
                continue;
            int prtitionCount = helper(st, idx + 1, s);
            if (prtitionCount == INT_MIN)
                continue;
            int totalCount = 1 + prtitionCount;

            maxi = max(maxi, totalCount);
        }
        return maxi;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        set<string> st(words.begin(), words.end());
        vector<string> ans;
        for (auto str : words)
        {
            if (helper(st, 0, str) >= 2)
                ans.push_back(str);
        }
        return ans;
    }
};