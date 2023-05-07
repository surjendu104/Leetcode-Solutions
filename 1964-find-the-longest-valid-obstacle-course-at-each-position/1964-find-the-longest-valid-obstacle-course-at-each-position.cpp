class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& A) {
        vector<int> res, mono;
        for (int a : A) {
            int l = 0, r = mono.size();
            while (l < r) {
                int m = (l + r) / 2;
                if (mono[m] <= a)
                    l = m + 1;
                else
                    r = m;
            }
            res.push_back(l + 1);
            if (mono.size() == l)
                mono.push_back(a);
            mono[l] = a;
        }
        return res;
    }
};