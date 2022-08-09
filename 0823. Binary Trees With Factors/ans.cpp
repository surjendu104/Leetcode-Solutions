class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        map<int, long long int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = 1;
        }
        for (int i = 0; i < n; i++)
        {

            auto it2 = mp.find(arr[i]);
            long long int count = 0;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0)
                {
                    auto it = mp.find(arr[i] / arr[j]);
                    auto it1 = mp.find(arr[j]);
                    if (it != mp.end())
                    {
                        count += (it->second) * (it1->second);
                    }
                }
            }
            it2->second += count;
        }
        long long ans = 0;
        for (auto it : mp)
            ans += it.second;
        return ans % 1000000007;
    }
};