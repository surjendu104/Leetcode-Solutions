// TLE
class Solution
{
public:
    set<string> st;
    void solve(string s, int idx, int n, string ans)
    {
        if (idx == n)
            return;

        if (!ans.empty())
            st.insert(ans);

        for (int i = idx + 1; i < n; i++)
        {
            ans += s[i];
            solve(s, i, n, ans);
            ans.erase(ans.size() - 1);
        }
        return;
    }
    int numMatchingSubseq(string s, vector<string> &words)
    {
        string ans;
        int count = 0;
        solve(s, -1, s.size(), ans);

        // for()
        for (int i = 0; i < words.size(); i++)
        {
            if (st.count(words[i]) != 0)
                count++;
        }
        return count;
    }
};

/*Runtime: 373 ms, faster than 51.10% of C++ online submissions for Number of Matching Subsequences.
Memory Usage: 50 MB, less than 48.09% of C++ online submissions for Number of Matching Subsequences.*/
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        map<char, vector<int>> mpp;
        for (int i = 0; i < s.size(); i++)
            mpp[s[i]].push_back(i);
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string x = words[i];
            int curr = -1;
            for (int j = 0; j < words[i].size(); j++)
            {
                auto it = upper_bound(mpp[x[j]].begin(), mpp[x[j]].end(), curr);
                if (it == mpp[x[j]].end())
                    break;
                curr = *it;
                if (j == x.size() - 1)
                    count++;
            }
        }
        return count;
    }
};