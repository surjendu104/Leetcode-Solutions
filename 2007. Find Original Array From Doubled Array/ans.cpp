
// TLE SOLUTION
class Solution
{
public:
    int find_next_unvisited(vector<int> &v, vector<int> &vis, int tar)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == tar and vis[i] == 0)
                return i;
        }
        return -1;
    }
    vector<int> findOriginalArray(vector<int> &c)
    {
        int n = c.size();
        vector<int> ans;

        if (n % 2)
            return ans;

        vector<int> vis(n, 0);
        sort(c.begin(), c.end());

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 1)
                continue;
            else
            {
                vis[i] = 1;
                int x = find_next_unvisited(c, vis, 2 * c[i]);
                cout << x << " ";
                if (x == -1)
                    continue;
                else
                {
                    ans.push_back(c[i]);
                    vis[x] = 1;
                }
            }
        }

        if (2 * ans.size() == n)
            return ans;
        ans.clear();
        return ans;
    }
};

// Accepted Solution
class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &c)
    {
        int n = c.size();
        vector<int> ans;

        // If the number of element in changed array is odd then there is no chance of getting double of all number
        if (n % 2)
            return ans;

        sort(c.begin(), c.end());
        unordered_map<int, int> mp; // Take the track of frequency of each element
        for (int i : c)
            mp[i]++;

        for (int i = 0; i < n; i++)
        {
            if (mp[c[i]] == 0)
                continue;
            else
            {
                if (mp.find(2 * c[i]) != mp.end())
                {
                    /*
                        If the element is 0 then it will find the same
                        So we have to do -2 from frequency
                    */
                    if (c[i] == 0 and mp[c[i]] >= 2)
                    {
                        ans.push_back(c[i]);
                        mp[c[i]] -= 2;
                    }
                    /*
                        Else decreament the frequency of each element
                    */
                    else if (c[i] != 0 and mp[2 * c[i]] != 0)
                    {
                        ans.push_back(c[i]);
                        mp[c[i]]--;
                        mp[2 * c[i]]--;
                    }
                }
            }
        }

        if (2 * ans.size() == n)
            return ans;
        ans.clear();
        return ans;
    }
};