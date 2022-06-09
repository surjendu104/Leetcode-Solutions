#include <bits/stdc++.h>
using namespace std;

/*Runtime: 36 ms, faster than 5.14% of C++ online submissions for Two Sum II - Input Array Is Sorted.
Memory Usage: 15.8 MB, less than 6.15% of C++ online submissions for Two Sum II - Input Array Is Sorted.*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        vector<int> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[numbers[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (m.find(target - numbers[i]) != m.end())
            {
                ans.push_back(i + 1);
                ans.push_back(m[target - numbers[i]] + 1);
                break;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();

        int i = 0, j = n - 1;

        while (i < j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                return {i + 1, j + 1};
            }
            else if (numbers[i] + numbers[j] > target)
            {
                --j;
            }
            else
            {
                ++i;
            }
        }

        return {0, 0};
    }
};
