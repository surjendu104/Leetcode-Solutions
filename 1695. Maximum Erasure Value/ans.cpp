#include <bits/stdc++.h>
using namespace std;

/*Runtime: 808 ms, faster than 10.45% of C++ online submissions for Maximum Erasure Value.
Memory Usage: 127.2 MB, less than 35.12% of C++ online submissions for Maximum Erasure Value.*/
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> st;
        int i = 0, tempSum = 0, ans = 0;

        for (int j = 0; j < n; j++)
        {
            while (st.find(nums[j]) != st.end())
            {
                st.erase(nums[i]);
                tempSum -= nums[i];
                i++;
            }
            st.insert(nums[j]);
            tempSum += nums[j];
            ans = max(ans, tempSum);
        }
        return ans;
    }
};