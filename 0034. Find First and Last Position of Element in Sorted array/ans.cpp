class Solution
{
public:
    vector<int> searchRange(vector<int> &N, int T)
    {
        int Tleft = find(T, N);
        if (Tleft == N.size() || N[Tleft] != T)
            return {-1, -1};
        return {Tleft, find(T + 1, N, Tleft) - 1};
    }
    int find(int target, vector<int> arr, int left = 0)
    {
        int right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + right >> 1;
            if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};

/*

88 / 88 test cases passed.
Status: Accepted
Runtime: 16 ms
Memory Usage: 13.7 MB

*/

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v;
        if (nums.empty())
            return {-1, -1};
        if ((find(nums.begin(), nums.end(), target) - nums.begin()) > nums.size() - 1)
            return {-1, -1};
        int first_pos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int last_pos = (upper_bound(nums.begin(), nums.end(), target) - nums.begin()) - 1;

        // if(first_pos>nums.size()-1)first_pos=-1;
        // if(last_pos>nums.size())last_pos=-1;
        v.push_back(first_pos);
        v.push_back(last_pos);

        return v;
    }
};