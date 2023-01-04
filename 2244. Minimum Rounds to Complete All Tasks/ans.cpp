class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> mp;
        for (int i : tasks)
            mp[i]++;

        int ans = 0;
        for (auto i : mp)
        {
            int x = i.second;
            if (x < 2)
                return -1;
            else if (x % 3 == 0)
                ans += (x / 3);
            else
            {
                ans = ans + (x / 3) + 1;
            }
        }
        return ans;
    }
};