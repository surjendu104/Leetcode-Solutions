class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> map;
        int cnt = 0;
        
        for(int i = 0; i < n; ++i) {
            int x = (arr[i]%k+k)%k;
            if(x == 0) {
                if(map.find(x) != map.end()) {
                    cnt++;
                    map[x]--;
                    if(map[x] == 0)map.erase(x);
                }else {
                    map[x]++;
                }
            }
            else if(map.find(k-x) != map.end()) {
                map[k-x]--;
                cnt++;
                if(map[k-x] == 0)map.erase(k-x);
            }
            else map[x]++;
        }
        if(2 * cnt >= n)return true;
        return false;
    }
};