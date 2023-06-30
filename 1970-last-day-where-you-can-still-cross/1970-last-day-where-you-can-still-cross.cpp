class Solution {
public:
    bool isPossibleToReachBottom(int mid, int row, int col, vector<vector<int>> &cells) {
        vector<vector<int>> mat(row, vector<int> (col)), vis(row, vector<int> (col));
        for(int i = 0; i < mid; i++) {
            int x = cells[i][0] - 1, y = cells[i][1] - 1;
            mat[x][y] = 1;
        }
        
        queue<pair<int, int>> q;
        for(int j = 0; j < col; j++) {
            if(mat[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }

        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            int x = p.first, y = p.second;            
            if(x == row - 1)
                return true;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 and ny >= 0 and nx < row and ny < col and mat[nx][ny] == 0 and !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 1, high = cells.size(), res = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossibleToReachBottom(mid, row, col, cells)) 
                res = mid, low = mid + 1;
            else high = mid - 1;
        } 

        return res;
    }
};