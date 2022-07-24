class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // for(int i=0,j=matrix.size()-1;i<matrix.size() and j>=0;){
        //     if(matrix[i][j]<target)i++;
        //     else if(matrix[i][j]>target)j--;
        //     else return true;
        // }

        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() and j >= 0)
        {
            if (matrix[i][j] > target)
                j--;
            else if (matrix[i][j] < target)
                i++;
            else
                return true;
        }
        return false;
    }
};