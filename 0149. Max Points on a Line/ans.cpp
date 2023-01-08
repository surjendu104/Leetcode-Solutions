class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int ans = 1;
        for (int i = 0; i < n - 1; i++)
        {
            map<double, int> mp;
            for (int j = i + 1; j < n; j++)
            {
                if (points[j][1] == points[i][1])
                {
                    mp[-90]++;
                }
                else
                {
                    double slope = (double)(points[j][0] - points[i][0]) / (double)(points[j][1] - points[i][1]);
                    mp[slope]++;
                }
            }

            int temp = 0;
            for (auto idx : mp)
            {
                temp = max(idx.second + 1, temp);
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};