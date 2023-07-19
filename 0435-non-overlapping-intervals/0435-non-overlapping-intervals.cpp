class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        int prev = 0;
        int cnt = 1;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= intervals[prev][1]) {
                prev = i;
                cnt++;
            }
        }
        return intervals.size()-cnt;
    }
};