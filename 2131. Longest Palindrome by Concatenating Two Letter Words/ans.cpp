class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> mp;
        int ans = 0;
        for (string s : words)
        {
            string p = s;
            reverse(p.begin(), p.end());
            if (mp[p] > 0)
            {
                ans += 4;
                mp[p]--;
            }
            else
            {
                mp[s]++;
            }
        }
        for (auto i : mp)
        {
            if (i.first[0] == i.first[1] and i.second > 0)
                return ans + 2;
        }
        return ans;
    }
};