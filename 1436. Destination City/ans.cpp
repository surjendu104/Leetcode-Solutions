#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, bool> mp;
        for (int i = 0; i < paths.size(); i++)
        {
            if (!mp[paths[i][0]])
                mp[paths[i][0]] = true;
        }

        string ans = "";
        for (int i = 0; i < paths.size(); i++)
        {
            if (!mp[paths[i][1]])
            {
                return paths[i][1];
            }
        }
        return ans;
    }
};

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        int n = paths.size();
        set<string> st;

        for (int i = 0; i < n; i++)
        {
            st.insert(paths[i][0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (st.count(paths[i][1]) == 0)
                return paths[i][1];
        }
        return "";
    }
};