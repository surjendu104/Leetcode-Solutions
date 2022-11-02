class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        queue<string> q;
        map<string, int> mp;
        mp[start] = 0;
        q.push(start);
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (auto v : bank)
            {
                if (mp.count(v))
                    continue;
                int cnt = 0;
                for (int i = 0; i < 8; i++)
                {
                    if (u[i] != v[i])
                        cnt++;
                }
                if (cnt == 1)
                {
                    mp[v] = mp[u] + 1;
                    q.push(v);
                }
            }
        }
        if (mp.count(end))
            return mp[end];
        return -1;
    }
};