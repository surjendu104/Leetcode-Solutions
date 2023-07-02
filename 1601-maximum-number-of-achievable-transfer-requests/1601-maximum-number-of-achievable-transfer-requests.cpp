class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size(), num[n], ans = 0;
        for(int i = 0; i < (1<<m); i++){
            fill_n(num, n, 0);
            int cnt = __builtin_popcount(i);;
            bool check = false;
            for(int j = 0; j < m; j++){
                if(i & (1<<j)){
                    num[requests[j][0]]--;
                    num[requests[j][1]]++;
                }
            }
            for(int j = 0; j < n; j++){
                if(num[j] != 0){
                    check = true;
                    break;
                }
            }
            if(!check) ans = max(ans, cnt);
        }
        return ans;
    }
};