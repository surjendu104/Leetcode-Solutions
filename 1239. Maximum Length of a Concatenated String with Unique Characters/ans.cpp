// TLE Solution
#include <bits/stdc++.h>
class Solution
{
public:
    int ans = 0;
    void f(vector<string> &arr, int idx, int n, vector<string> &ds)
    {
        if (idx == n)
        {
            set<char> st;
            string s;
            for (int i = 0; i < ds.size(); i++)
                s += ds[i];
            for (int i = 0; i < s.size(); i++)
                st.insert(s[i]);
            if (st.size() == s.size())
            {
                if (ans < s.size())
                    ans = s.size();
            }
            st.clear();
            return;
        }
        ds.push_back(arr[idx]);
        f(arr, idx + 1, n, ds);
        ds.pop_back();
        f(arr, idx + 1, n, ds);
    }
    int maxLength(vector<string> &arr)
    {
        vector<string> ds;
        f(arr, 0, arr.size(), ds);
        return ans;
    }
};

// Accepted
class Solution
{
public:
    int check(string &s)
    {
        set<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.count(s[i]) == 1)
                return -1;
            st.insert(s[i]);
        }
        return st.size();
    }
    int solve(vector<string> &arr, int idx, int n, string curr)
    {
        if (idx == n)
            return check(curr);
        if (check(curr) == -1)
            return -1;

        int take = solve(arr, idx + 1, n, curr + arr[idx]);
        int not_take = solve(arr, idx + 1, n, curr);
        return max(take, not_take);
    }
    int maxLength(vector<string> &arr)
    {
        string curr = "";
        return solve(arr, 0, arr.size(), curr);
    }
};
