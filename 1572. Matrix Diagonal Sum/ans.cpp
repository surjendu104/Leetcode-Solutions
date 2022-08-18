class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int s = 0;
        for (int i = 0; i < n; i++)
            s += mat[i][i];
        int j = mat.size() - 1;
        for (int i = 0; i < n; i++)
        {
            s += mat[i][j];
            j--;
        }
        if (n % 2)
            return s - mat[n / 2][n / 2];
        return s;
    }
};