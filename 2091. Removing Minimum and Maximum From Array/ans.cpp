/*Runtime: 232 ms, faster than 57.00% of C++ online submissions for Removing Minimum and Maximum From Array.
Memory Usage: 88.3 MB, less than 80.69% of C++ online submissions for Removing Minimum and Maximum From Array.*/

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;
        int mini = INT_MAX, minId, maxi = INT_MIN, maxId;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > maxi)
            {
                maxi = nums[i];
                maxId = i;
            }
            if (nums[i] < mini)
            {
                mini = nums[i];
                minId = i;
            }
        }
        int x=min(maxId,minId),y=max(maxId,minId);
        return min(n-(y-x-1),y+1,n-x);
    }
};