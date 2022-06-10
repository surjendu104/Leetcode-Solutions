#include <bits/stdc++.h>
#include<iostream>
using namespace std;


/*Runtime: 239 ms, faster than 37.20% of C++ online submissions for Subarrays with K Different Integers.
Memory Usage: 56.2 MB, less than 7.26% of C++ online submissions for Subarrays with K Different Integers.*/
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMostK(nums,k)-atMostK(nums,k-1);
    }


    int atMostK(vector<int>&nums,int k){
        int i=0,j=0,count=0;
        unordered_map<int,int>mpp;

        while(i<nums.size()){
            mpp[nums[i]]++;
            while(mpp.size()>k){
                auto it = mpp.find(nums[j]);
                it->second--;
                if(it->second==0)mpp.erase(it);
                j++;
            }
            count += i-j+1;
            i++;
        }  
        return count;
    }
};
