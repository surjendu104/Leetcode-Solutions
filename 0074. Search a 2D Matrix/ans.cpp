class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int row = matrix.size();
        int col = matrix[0].size();
        int l = 0;
        int r = row * col - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int val = matrix[mid / col][mid % col];
            if (val == target)
                return true;
            if (val > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return false;
    }
};