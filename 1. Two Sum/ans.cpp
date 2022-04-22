class Solution
{
public:
    vector<int> twoSum(vector<int> &a, int n)
    {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int i = 0; i < a.size(); i++)
        {
            if (mpp.find(n - a[i]) != mpp.end())
            {
                ans.push_back(mpp[n - a[i]]);
                ans.push_back(i);
            }
            mpp[a[i]] = i;
        }
        return ans;
    }
};