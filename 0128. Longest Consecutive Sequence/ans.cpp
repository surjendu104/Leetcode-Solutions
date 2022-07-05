/*Runtime: 117 ms, faster than 85.84% of C++ online submissions for Longest Consecutive Sequence.
Memory Usage: 33.8 MB, less than 85.63% of C++ online submissions for Longest Consecutive Sequence.*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi=1,curr = 1;

        if(nums.size()==0)return maxi=0;

        sort(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                curr++;
                maxi = max(maxi,curr);
            }
            else if(nums[i]==nums[i-1])curr=curr;
            else curr =1;
        }
        return maxi;
    }
};