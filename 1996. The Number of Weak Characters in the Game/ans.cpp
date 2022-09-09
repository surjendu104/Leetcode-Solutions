#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &p)
    {
        int n = p.size();
        sort(p.begin(), p.end(), [](auto &a, auto &b)
             { return ((a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0])); });
        // for(auto i:p)cout<<i[0]<<" "<<i[1]<<endl;
        int ans = 0, max_defence_till_now = p[p.size() - 1][1];
        for (int i = p.size() - 2; i >= 0; i--)
        {
            if (p[i][1] < max_defence_till_now)
                ans++;
            max_defence_till_now = max(max_defence_till_now, p[i][1]);
        }
        return ans;
    }
};