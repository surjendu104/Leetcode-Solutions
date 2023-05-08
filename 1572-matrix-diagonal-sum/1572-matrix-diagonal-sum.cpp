class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        for(int i = 0; i<n;i++) {
            ans += mat[i][i];
        }
        int j = 0;
        for(int i = n-1; i >= 0; --i) {
            ans += mat[j][i];
            j++;
        }
        if(n%2)ans-=mat[n/2][n/2];
        return ans;
    }
};