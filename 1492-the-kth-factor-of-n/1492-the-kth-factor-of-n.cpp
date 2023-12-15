class Solution {
public:
    int kthFactor(int n, int k) {
        if(n == 1 && k == 1) return 1;
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(n % i == 0) {
                cnt++;
                // cout << n << " " << i  << " " << cnt << '\n';
            }
            if(cnt == k) return i;
        }
        return -1;
    }
};