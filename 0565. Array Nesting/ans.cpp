// TLE Solution
class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            map[i] = nums[i];
        }
        int maxi = INT_MIN;
        for (int i = 0; i < map.size(); i++)
        {
            int x = map[i];
            int cnt = 0;
            while (x != map[x])
            {
                cnt++;
                x = map[x];
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};

// Accepted
class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int ans = INT_MIN;
        vector<bool> vis(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            while (!vis[i])
            {
                vis[i] = true;
                cnt++;
                i = nums[i];
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};