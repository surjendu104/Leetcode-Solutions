class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        vector<int> dirs = {0, 1, 0, -1, 0};
        int dir = 0;
        int r = 0, c = 0;
        int k = 1;
        
        while(k <= n*n){
            ans[r][c] = k++;
            
            if(ans[(r + n + dirs[dir])%n][(c + n + dirs[dir+1])%n] != 0){
                dir = (dir+1) % 4;
            }
            
            r += dirs[dir];
            c += dirs[dir+1];
        }
        
        return ans;
    }
};