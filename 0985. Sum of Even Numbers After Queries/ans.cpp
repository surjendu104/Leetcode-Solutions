class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n=q.size();
        vector<int>ans;
        
        int sum =0;
        for(int i:nums){
            if(i%2==0)sum+=i;
        }
        
        for(auto i:q){
            int val = i[0];
            int idx = i[1];
            if(nums[idx]%2==0)sum-=nums[idx];
            nums[idx]+=val;
            if(nums[idx]%2==0)sum+=nums[idx];
            
            ans.push_back(sum);
        }
        return ans;
    }
};