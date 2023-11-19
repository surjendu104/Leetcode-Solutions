class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int ii : nums) map[ii]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto it : map) pq.push({it.first, it.second});
        
        int cnt = 0;
        while(pq.size() > 1) {
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();
            cnt += x.second;
            pq.push({y.first, y.second + x.second});
        }
        return cnt;
    }
};