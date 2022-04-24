class Solution
{
public:
    bool search(vector<int> &nums, int &target)
    {
        int n = nums.size();
        if (n == 0)
            return false;
        int left = 0, right = n - 1;
        while (left <= right)
        { // Dichotomy, left and right pointer
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < nums[right])
            { // The middle value is less than the value on the right, then the right half is in order
                if (nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if (nums[mid] > nums[right])
            { // The middle value is greater than the left value, then the left half is ordered (same ascending space)
                if (nums[left] <= target && nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
                --right; // When the middle value is equal to the rightmost value, just move the right pointer to the left
        }
        return false; // Not found
    }
};