class Solution
{
public:
    int searchInsert(vector<int> &a, int target)
    {
        int left = 0, right = a.size() - 1, pos;

        while (left <= right)
        {
            int mid = (right + left) / 2;
            if (a[mid] == target)
            {
                return mid;
            }
            else if (a[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};