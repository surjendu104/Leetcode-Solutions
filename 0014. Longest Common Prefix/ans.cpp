class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        int ans = INT_MAX;
        for (int i = 0; i < strs.size() - 1; i++)
        {
            ans = min(ans, (int)min(strs[i].size(), strs[i + 1].size()));
            while (strs[i].substr(0, ans) != strs[i + 1].substr(0, ans))
            {
                ans--;
            }
            if (ans == 0)
                return "";
        }
        return strs[0].substr(0, ans);
    }
};
