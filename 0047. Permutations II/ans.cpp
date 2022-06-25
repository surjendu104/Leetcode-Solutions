/*Runtime: 116 ms, faster than 16.39% of C++ online submissions for Permutations II.
Memory Usage: 9.3 MB, less than 57.07% of C++ online submissions for Permutations I*/


class Solution {
public:
    set<vector<int>> store;
    void find_permutation(vector<int> &nums,vector<int> &vis,vector<int> &temp){
        
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                temp.push_back(nums[i]);
                find_permutation(nums,vis,temp);
                temp.pop_back();
                vis[i]=0;
            }    
        }
        if(temp.size()==nums.size()){
              store.insert(temp);
        }
      
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       
        int n=nums.size();
        vector<int> vis(n,0);
        vector<int> temp;
        int current=0;
        find_permutation(nums,vis,temp);
        vector<vector<int>> ans(store.begin(),store.end());
        return  ans;
        
    }
};