class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }
        for (auto i : mp)
        {
            if (i.second.size() > 1)
            {
                for (int idx = 0; idx < i.second.size() - 1; idx++)
                {
                    if (abs(i.second[idx] - i.second[idx + 1]) <= k)
                        return true;
                }
            }
        }
        return false;
    }
};