class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        vector<int> v;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
                v.push_back(matrix[i][j]);
        }
        sort(v.begin(), v.end());
        return v[k - 1];
    }
};

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();

        int l = matrix[0][0], h = matrix[n - 1][n - 1];
        while (l < h)
        {
            int mid = l + (h - l) / 2;
            int temp = n - 1;
            int c = 0;

            for (int i = 0; i < n; i++)
            {
                while (temp >= 0 and matrix[i][temp] > mid)
                    temp--;
                c += (temp + 1);
            }
            if (c < k)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};