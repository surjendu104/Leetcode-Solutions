#include<bits/stdc++.h>
using namespace std;

//Sliding window
/*Runtime: 304 ms, faster than 52.53% of C++ online submissions for Jump Game VI.
Memory Usage: 77.3 MB, less than 99.05% of C++ online submissions for Jump Game VI.*/
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int>d{0};
        for(int i=1;i<nums.size();i++){
            if(d.front()+k<i){
                d.pop_front();
            }
            nums[i]+=nums[d.front()];
            while(!d.empty() and nums[d.back()]<=nums[i])
                d.pop_back();
            d.push_back(i);
        }
        return nums.back();
    }
};


//Dp Solution
/*Runtime: 467 ms, faster than 18.68% of C++ online submissions for Jump Game VI.
Memory Usage: 93.8 MB, less than 40.42% of C++ online submissions for Jump Game VI.*/
class Solution{
    public:
        int maxResult(vector<int>&v,int k){
            int n=v.size();
            vector<int>dp(n);

            dp[n-1] =v[n-1];
            priority_queue<pair<int,int>>max_upto;
            max_upto.push({dp[n-1],n-1});

            for(int i=n-2;i>=0;i--){
                while(max_upto.size() and max_upto.top().second>i+k)max_upto.pop();

                dp[i] = v[i]+max_upto.top().first;
                max_upto.push({dp[i],i});
            }
            return dp[0];
        }
};