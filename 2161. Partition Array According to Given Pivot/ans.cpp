#include <bits/stdc++.h>
using namespace std;

/*Runtime: 279 ms, faster than 51.74% of C++ online submissions for Partition Array According to Given Pivot.
Memory Usage: 127 MB, less than 66.20% of C++ online submissions for Partition Array According to Given Pivot.*/
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> temp;
        int count = 0, j = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
                nums[j++] = nums[i];
            else if (nums[i] == pivot)
                count++;
            else
                temp.push_back(nums[i]);
        }
        while (count--)
            nums[j++] = pivot;
        for (int i = 0; i < temp.size(); i++)
            nums[j++] = temp[i];
        return nums;
    }
};

/*Runtime: 434 ms, faster than 6.49% of C++ online submissions for Partition Array According to Given Pivot.
Memory Usage: 123.4 MB, less than 82.26% of C++ online submissions for Partition Array According to Given Pivot.*/
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int high = 0, low = 0, same = 0;

        for (int i : nums)
        {
            if (i < pivot)
                low++;
            if (i == pivot)
                same++;
        }
        high = low + same;
        same = low;
        low = 0;

        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(), i++)
        {
            if (nums[i] < pivot)
                ans[low++] = nums[i];
            else if (nums[i] == pivot)
                ans[same++] = nums[i];
            else
                ans[high++] = nums[i];
        }
        return ans;
    }
};


/*Runtime: 354 ms, faster than 21.22% of C++ online submissions for Partition Array According to Given Pivot.
Memory Usage: 133 MB, less than 27.51% of C++ online submissions for Partition Array According to Given Pivot.*/
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> low, high;
        int count = 0;
        for (int i : nums)
        {
            if (i < pivot)
                low.push_back(i);
            if (i == pivot)
                count++;
            else
                high.push_back(i);
        }
        while (count--)
            low.push_back(pivot);
        for (int i : high)
            low.push_back(i);
        return low;
    }
};