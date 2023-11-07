/*
For this problem if the arrival time greater than the current minute then break.
*/

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> arrivalTime(n, 0.0);
        int ans = 0;
        
        for(int i = 0; i < n; ++i) arrivalTime[i] = (double)dist[i] / speed[i];
        
        sort(begin(arrivalTime), end(arrivalTime));
        for(int i = 0; i < n; ++i) {
            if(arrivalTime[i] > i) ans++;
            else break;
        }
        return ans;
    }
};