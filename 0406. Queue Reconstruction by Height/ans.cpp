/*Runtime: 367 ms, faster than 10.31% of C++ online submissions for Queue Reconstruction by Height.
Memory Usage: 24.7 MB, less than 9.64% of C++ online submissions for Queue Reconstruction by Height.*/

class Solution
{
    static bool comp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), comp);

        vector<vector<int>> ans;
        for (int i = 0; i < people.size(); i++)
        {
            ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};