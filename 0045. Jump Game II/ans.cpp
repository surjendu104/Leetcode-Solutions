
//another greedy 
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int curr=0,next=0,jump=0;
        for(int i=0;i<n-1;i++){
            next=max(next,i+nums[i]);
            
            if(i==curr){
                jump++;
                curr=next;
            }
        }
        return jump;
    }
};