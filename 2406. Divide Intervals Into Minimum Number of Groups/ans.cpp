#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minGroups(vector<vector<int>> &in)
    {
        // unordered_map<vector<int>,int>mp;

        sort(in.begin(), in.end(), [](auto &a, auto &b)
             { return a[0] < b[0]; });

        priority_queue<int, vector<int>, greater<>> pq;

        for (auto &i : in)
        {
            if (!pq.empty() && pq.top() < i[0])
            {
                pq.pop();
            }
            pq.emplace(i[1]);
        }
        return pq.size();
    }
};