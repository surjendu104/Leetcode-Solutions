class Solution
{
public:
    int garbageCollection(vector<string> &g, vector<int> &t)
    {
        int ans = 0;
        int n = g.size();
        for (int i = 0; i < n; i++)
        {
            ans += g[i].size();
        }

        vector<int> v(n - 1);
        v[0] = t[0];
        for (int i = 1; i < t.size(); i++)
        {
            v[i] = v[i - 1] + t[i];
        }
        int x = 0, y = 0, z = 0;
        for (int i = 0; i < n; i++)
        {
            if (g[i].find('M') != string::npos)
            {
                x = i;
            }
            if (g[i].find('G') != string::npos)
            {
                y = i;
            }
            if (g[i].find('P') != string::npos)
            {
                z = i;
            }
        }
        // cout<<x<<" "<<y<<" "<<z<<endl;

        if (x > 0)
            ans += v[x - 1];
        if (y > 0)
            ans += v[y - 1];
        if (z > 0)
            ans += v[z - 1];
        return ans;
    }
};