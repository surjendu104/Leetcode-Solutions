class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (int i : nums)
            mp[i]++;

        int a = INT_MIN;
        for (auto i : mp)
        {
            if (i.first % 2 == 0)
                a = max(a, i.second);
        }

        vector<int> v;
        for (auto i : mp)
        {

            if (i.first % 2 == 0 && i.second == a)
            {
                v.push_back(i.first);
            }
        }
        return (v.size() == 0) ? -1 : *min_element(v.begin(), v.end());
    }
};