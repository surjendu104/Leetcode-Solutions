class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for(int i : nums) pq.push(i);
        long long tmp = 0;
        int y = k;
        while(y-- && pq.size()) {
            int x = pq.top();
            pq.pop();
            tmp += x;
        }
        ans = max(ans, tmp);
        pq =  priority_queue<int>();
        
        for(int i : nums) pq.push(i);
        tmp = 0;
        while(k-- && pq.size()) {
            int x = pq.top();
            pq.pop();
            tmp += x;
            //cout << "@@ " << ceil(x / 3) << '\n';
            int y = x %3 != 0 ? (x / 3) + 1 : (x / 3); 
            pq.push(y);
        }
        ans = max(ans, tmp);
        return ans;
    }
};