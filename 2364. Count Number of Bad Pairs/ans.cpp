#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, long long> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]-i]++;
        }
        long long ans = (long long)n*(n-1)/2;
        for(auto i:map) {
            cout<<i.first<<" "<<i.second<<endl;
            if(i.second>1)ans-=((long long)i.second*(i.second-1)/2);
        }
        return ans;
    }
};


//Approach : 2
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int,int>map;
        for(int i= 0;i<nums.size();i++) {
            // map[i-nums[i]] is the number of good pair appear before i
            // i - map[i-nums[i]] is the number of bad pair appear before i
            // doing map[i-nums[i]]++ because every pair count at once
            ans += i-map[i-nums[i]]++;
        }
        return ans;
    }
};