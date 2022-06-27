/* Runtime: 31 ms, faster than 87.44% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
Memory Usage: 13.6 MB, less than 17.75% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers. */

class Solution
{
public:
    int minPartitions(string n)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < n.size(); i++)
        {
            maxi = max(maxi, n[i] - '0');
        }
        return maxi;
    }
};