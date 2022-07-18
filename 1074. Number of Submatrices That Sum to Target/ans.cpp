
#include <bits/stdc++.h>
using namespace std;
/*Runtime: 2833 ms, faster than 5.11% of C++ online submissions for Number of Submatrices That Sum to Target.
Memory Usage: 9 MB, less than 94.64% of C++ online submissions for Number of Submatrices That Sum to Target.*/
//O(N^4) solution
class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                matrix[i][j] += matrix[i][j - 1];
        for (int j = 0; j < m; j++)
            for (int i = 1; i < n; i++)
                matrix[i][j] += matrix[i - 1][j];

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = i; k < n; k++)
                {
                    for (int l = j; l < m; l++)
                    {
                        int sum = matrix[k][l];
                        if (j > 0)
                            sum -= matrix[k][j - 1];
                        if (i > 0)
                            sum -= matrix[i - 1][l];
                        if (i > 0 and j > 0)
                            sum += matrix[i - 1][j - 1];
                        if (sum == target)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};