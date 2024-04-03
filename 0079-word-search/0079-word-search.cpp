class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool dfs(vector<vector<char>>& g, vector<vector<int>>& vis, string w, int idx, int i, int j, int n, int m) {
        if(idx == w.size()) return true;
        if(i < 0 || i >= n || j < 0 || j >= m || g[i][j] != w[idx] || vis[i][j]) return false;
        
        vis[i][j] = 1;
        for(int k = 0; k < 4; ++k) {
            int r = i + dir[k].first;
            int c = j + dir[k].second;
            if(dfs(g, vis, w, idx+1, r, c, n, m)) return true;
        }
        vis[i][j] = 0;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(board[i][j] == word[0] && dfs(board, vis, word, 0, i, j, n, m))
                    return true;
            }
        }
        return false;
    }
};