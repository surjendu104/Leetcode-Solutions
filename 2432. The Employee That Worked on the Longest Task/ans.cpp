class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        map<int, int> m;

        m[logs[0][0]] = logs[0][1];

        for (int i = 1; i < logs.size(); i++)
        {
            if (m.find(logs[i][0]) != m.end())
            {
                m[logs[i][0]] = max(m[logs[i][0]], logs[i][1] - logs[i - 1][1]);
            }
            else
                m[logs[i][0]] = (logs[i][1] - logs[i - 1][1]);
        }
        int maxShift = INT_MIN, id;
        for (auto i : m)
        {
            if (i.second > maxShift)
            {
                maxShift = i.second;
                id = i.first;
            }
        }
        return id;
    }
};