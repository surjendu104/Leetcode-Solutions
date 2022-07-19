/*Runtime: 5 ms, faster than 20.24% of C++ online submissions for Pascal's Triangle II.
Memory Usage: 6.7 MB, less than 16.60% of C++ online submissions for Pascal's Triangle II.*/

class Solution
{
public:
    vector<int> getRow(int r)
    {
        vector<vector<int>> ans = {{1}};

        for (int i = 1; i < r + 1; ++i)
        {
            vector<int> v;
            v.push_back(1);
            for (int j = 1; j <= i - 1; j++)
            {
                v.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans[r];
    }
};