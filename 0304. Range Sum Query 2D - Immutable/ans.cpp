#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
    vector<vector<int>>dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size()+1,n=matrix[0].size()+1;
        dp = vector<vector<int>>(m,vector<int>(n,0));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = matrix[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
            
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (dp[row2+1][col2+1]-dp[row2+1][col1]-dp[row1][col2+1]+dp[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */