#include<bits/stdc++.h>
using namespace std;


/*Runtime: 789 ms, faster than 24.80% of C++ online submissions for Matchsticks to Square.
Memory Usage: 10.1 MB, less than 66.64% of C++ online submissions for Matchsticks to Square.*/
class Solution {
public:

    bool f(int idx,vector<int>&v,vector<int>&arr){
        if(idx>=v.size())return arr[0]==arr[1] and arr[1]==arr[2] and arr[2]==arr[3];

        for(int i=0;i<4;i++){
            if(arr[i]<v[idx])continue;

            arr[i]-=v[idx];
            if(f(idx+1,v,arr))return true;
            arr[i]+=v[idx];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()==0)return false;
        int x=accumulate(matchsticks.begin(),matchsticks.end(),0);

        if(x%4)return false;
        sort(matchsticks.rbegin(),matchsticks.rend());
        vector<int>side(4,x/4);
        return f(0,matchsticks,side);
    }
};