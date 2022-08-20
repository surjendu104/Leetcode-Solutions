class Solution
{
public:
    int minRefuelStops(int target, int now, vector<vector<int>> &stations)
    {
        int n = stations.size();
        if (n == 0)
        {
            if (target <= now)
                return 0;
            return -1;
        }
        sort(stations.begin(), stations.end());
        int prev = 0, cnt = 0;
        priority_queue<int> q;
        for (int i = 0; i < n; i++)
        {
            now -= (stations[i][0] - prev);
            prev = stations[i][0];
            if (now < 0)
            {
                while (!q.empty() && now < 0)
                {
                    now += q.top();
                    q.pop();
                    cnt++;
                }
                if (q.empty() && now < 0)
                    return -1;
            }
            q.push(stations[i][1]);
        }
        now -= (target - stations[n - 1][0]);
        if (now < 0)
        {
            while (!q.empty() && now < 0)
            {
                now += q.top();
                q.pop();
                cnt++;
            }
            if (q.empty() && now < 0)
                return -1;
        }
        return cnt;
    }
};