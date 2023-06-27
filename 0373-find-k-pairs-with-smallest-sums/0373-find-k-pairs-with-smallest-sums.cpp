class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        map<pair<int, int>, int> mpp;
        
        int i = 0, j = 0;
        pq.push({nums1[i]+nums2[j], i, j});
        mpp[{i,j}] = 1;
        
        while(pq.size() && k>0) {
            vector<int> tmp = pq.top();
            pq.pop();
            int i = tmp[1];
            int j = tmp[2];
            
            ans.push_back({nums1[i], nums2[j]});
            
            if(i+1 < n && !mpp[{i+1, j}]) {
                pq.push({nums1[i+1]+nums2[j], i+1, j});
                mpp[{i+1, j}]++;
            }
            if(j+1 < m && !mpp[{i, j+1}]) {
                pq.push({nums1[i]+nums2[j+1], i, j+1});
                mpp[{i, j+1}]++;
            }
            k--;
        }
        return ans;
    }
};