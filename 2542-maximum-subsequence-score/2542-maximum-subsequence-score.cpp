#define ll long long

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        ll ans = 0, sum = 0;
        for(int i = 0; i<nums1.size(); ++i) {
            v.push_back({nums2[i], nums1[i]});
        }
        
        sort(v.rbegin(),v.rend());
        for(int i = 0; i < nums1.size(); ++i) {
            sum+=v[i].second;
            pq.push(v[i].second);
            
            if(pq.size() < k)continue;
            if(pq.size()==k) {
                ans = max(ans, sum*v[i].first);
                sum-=pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};