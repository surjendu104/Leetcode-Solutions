class Solution
{
public:
    int trap(vector<int> &arr)
    {
        int n = arr.size();

        int result = 0;

        // maximum element on left and right
        int left_max = 0, right_max = 0;

        // indices to traverse the array
        int lo = 0, hi = n - 1;

        while (lo <= hi)
        {
            if (arr[lo] < arr[hi])
            {
                if (arr[lo] > left_max)
                    // update max in left
                    left_max = arr[lo];
                else
                    // water on curr element = max - curr
                    result += left_max - arr[lo];
                lo++;
            }
            else
            {
                if (arr[hi] > right_max)
                    // update right maximum
                    right_max = arr[hi];
                else
                    result += right_max - arr[hi];
                hi--;
            }
        }

        return result;
        // return water;
    }
};

// for each i ans = min(left[i],right[i])-a[i]
class Solution
{
public:
    int trap(vector<int> &h)
    {
        int n = h.size();

        vector<int> premax(n), sufmax(n);

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, h[i]);
            premax[i] = maxi;
        }
        maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            maxi = max(maxi, h[i]);
            sufmax[i] = maxi;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (min(premax[i], sufmax[i]) - h[i]);
        }
        return ans;
    }
};