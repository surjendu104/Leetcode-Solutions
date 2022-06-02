class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int total = 0, local = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            local = max(0, local + prices[i + 1] - prices[i]);
            total = max(total, local);
        }
        return total;
    }
};