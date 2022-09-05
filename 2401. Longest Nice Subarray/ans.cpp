class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int checker=0,ans=0,j=0;
        
        for(int i=0;i<n;i++){
            while((checker&nums[i])!=0){
                checker^=nums[j++];
            }
            checker|=nums[i];
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};