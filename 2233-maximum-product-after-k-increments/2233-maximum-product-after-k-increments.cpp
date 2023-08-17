class Solution {
public:
    int mod = 1000000007;
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : nums) pq.push(i);
        
        while(k--) {
            int x = pq.top()+1;
            // cout<<"dbg : "<<x<<endl;
            pq.pop();
            pq.push(x);
        }
        long long ans = 1;
        while(!pq.empty()) {
            ans = (ans*1LL*pq.top())%mod;
            pq.pop();
        }
        return ans%mod;
    }
};