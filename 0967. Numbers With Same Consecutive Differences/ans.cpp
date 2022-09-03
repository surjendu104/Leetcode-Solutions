#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(string &s, set<string> &st, int n, int idx, int k)
    {
        if (s.length() == n)
        {
            st.insert(s);
            return;
        }
        char c = s[s.length() - 1];
        int val = c - '0';
        int f = val + k, b = val - k;
        if (f <= 9)
        {
            char c1 = f + '0';
            string s2 = s;
            s2 += c1;
            solve(s2, st, n, idx + 1, k);
        }
        if (b >= 0)
        {
            char c1 = b + '0';
            string s2 = s;
            s2 += c1;
            solve(s2, st, n, idx + 1, k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        set<string> st;
        vector<int> ans;
        string s = "";
        for (int i = 1; i <= 9; i++)
        {
            char s1 = '0' + i;
            s = s1;
            solve(s, st, n, i + 1, k);
        }

        for (auto i : st)
        {
            int val = stoi(i);
            ans.push_back(val);
        }
        return ans;
    }
};