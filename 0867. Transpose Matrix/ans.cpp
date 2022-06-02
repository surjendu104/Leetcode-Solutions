// 1st Approach : By taking a new 1D array/vector and pushing new valus to it and after that pushing the result to resulting 2D vector

// Time Complexity : O(N^2)
// Space Complexity : O(N^2)

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            vector<int> v; // Declaring Empty vector
            for (int j = 0; j < matrix.size(); j++)
            {
                v.push_back(matrix[j][i]);
            }
            ans.push_back(v); // pushing the formed vector to resulting 2D vector
        }
        return ans;
    }
};

// 2nd Approach : Taking paraller resulting vector and assigning the reverse (col,row of given matrix to ans vector) value to ans vector

// Time Complexity : O(N^2)
// Space Complexity : O(N^2)

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i][j] = matrix[j][i];
            }
        }
        return ans;
    }
};
