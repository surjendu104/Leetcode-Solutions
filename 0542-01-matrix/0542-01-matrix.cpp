class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int dr[4] = {-1,0,0,1};
        int dc[4] = {0,-1,1,0};
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(mat[i][j]==0) {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(q.size()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            dist[row][col] = distance;
            q.pop();
            for(int i = 0; i<4; i++) {
                int r = row+dr[i];
                int c = col+dc[i];
                if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0 && mat[r][c]==1) {
                    q.push({{r,c},distance+1});
                    vis[r][c] = 1;
                }
            }
        }
        return dist;
    }
};