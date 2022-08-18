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
        for (int i = 0; i < n; i++)
        {
            if (!mp[paths[i][1]])
            {
                return paths[i][1];
            }
        }
        return ans;
    }
};