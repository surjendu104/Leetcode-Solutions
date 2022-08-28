class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sortDiag;
        for (int k = m - 1; k > -n; k--)
        {
            vector<int> temp;
            for (int i = 0; i < m; i++)
            {
                if (i - k >= 0 && i - k < n)
                    temp.push_back(mat[i][i - k]);
            }
            sort(temp.begin(), temp.end());
            sortDiag.push_back(temp);
        }

        int iter = 0, curr;
        for (int k = m - 1; k > -n; k--)
        {
            curr = 0;
            for (int i = 0; i < m; i++)
            {
                if (i - k >= 0 && i - k < n)
                    mat[i][i - k] = sortDiag[iter][curr++];
            }
            iter++;
        }
        return mat;
    }
};