class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        auto check = [&](int ans) {
            for (auto i : tasks) {
                if (ans >= i[1]) {
                    ans -= i[0];
                } else {
                    return false;
                }
            }
            return true;
        };
        
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        
        int l = 0, h = 1e9;
        int ans = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(mid)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};