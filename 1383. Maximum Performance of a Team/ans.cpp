class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        long long maxPerformance_ = 0, sum = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int minEfficiency = v[i][0];
            sum += v[i][1];
            pq.push(v[i][1]);

            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            maxPerformance_ = max(maxPerformance_, sum * minEfficiency);
        }
        return maxPerformance_ % 1000000007;
    }
};