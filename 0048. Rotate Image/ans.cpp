class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){
                int temp = mat[i][j];
                mat[i][j] = mat[n-j-1][i];
                mat[n-j-1][i]=mat[n-1-i][n-1-j] ;
                mat[n-1-i][n-1-j] = mat[j][n-1-i];
                mat[j][n-1-i] = temp;
            }
        }
    }
};



class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>>ans(mat.size(),vector<int>(mat.size(),0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = mat[j][i];
            }
            reverse(ans[i].begin(),ans[i].end());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = ans[i][j];
            }
        }
    }
};