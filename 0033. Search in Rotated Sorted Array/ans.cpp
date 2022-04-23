class Solution
{
public:
    int search(vector<int> &a, int target)
    {
        int n = a.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // Check left portion is sorted or not
            if (a[mid] == target)
                return mid;
            if (a[low] <= a[mid])
            {
                if (a[low] <= target && a[mid] >= target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            else
            {
                if (target >= a[mid] && target <= a[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};