class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        if (costs[0] > coins)
            return 0;
        if (costs[0] == coins)
            return 1;
        int ans = 0;
        for (int i : costs)
        {
            if (coins >= i)
            {
                ans++;
                coins -= i;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};