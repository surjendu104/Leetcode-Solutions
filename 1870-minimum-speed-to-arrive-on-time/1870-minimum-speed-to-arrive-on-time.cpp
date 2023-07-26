class Solution {
public:
    bool ifPossible(int mid,vector<int>& d, double h) {
        double time = 0;
        for(int i = 0;i<d.size()-1;i++) {
            time+=ceil((double)d[i]/mid);
        }
        time+=(double)d[d.size()-1]/mid;
        return time<=h;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1,r = 1e9;
        int ans = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(ifPossible(mid,dist,hour)) {
                ans = mid;
                r = mid-1;
            }else l = mid+1;
        }
        return ans;
    }
};