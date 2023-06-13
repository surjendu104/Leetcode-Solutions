class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> tg(n, vector<int>(m));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                tg[i][j] = grid[j][i];
            }
        }
        unordered_map<string, int>mpp;
        vector<string> v;
        for(int i = 0; i < n; ++i) {
            string s = "";
            for(int j = 0; j < m; ++j) {
                s+="#"+to_string(tg[i][j]);
            }
            v.push_back(s);
        }
        
        for(string s : v) mpp[s]++;
        
        int cnt = 0;
        for(int i = 0; i< n; ++i) {
            string s = "";
            for(int j = 0; j< m; j++) {
                s+="#"+to_string(grid[i][j]);
            }
            if(mpp.find(s)!=mpp.end())cnt+=mpp[s];
        }
        return cnt;
    }
};