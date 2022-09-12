class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        vector<int> presum_mod_k(k);
        int pre_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pre_sum += nums[i];
            int res = pre_sum % k;
            res = (res < 0) ? res + k : res;
            presum_mod_k[res]++;
        }
        for (int i : presum_mod_k)
            cout << i << " ";
        int ans = presum_mod_k[0];
        for (int i : presum_mod_k)
        {
            if (i >= 2)
                ans += i * (i - 1) * 0.5;
        }
        return ans;
    }
};