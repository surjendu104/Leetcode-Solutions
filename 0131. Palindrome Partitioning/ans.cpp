class Solution
{
public:
    bool checkPalnindrome(int start, int end, string s)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
            // start++;end--;
        }
        return true;
    }

    void helper(int idx, string s, vector<string> &ds, vector<vector<string>> &ans)
    {
        if (idx == s.size())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < s.size(); i++)
        {
            if (checkPalnindrome(idx, i, s))
            {
                string str = s.substr(idx, i - idx + 1);
                ds.push_back(str);
                helper(i + 1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> ds;
        helper(0, s, ds, ans);
        return ans;
    }
};