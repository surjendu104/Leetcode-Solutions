#include<bits/stdc++.h>
using namespace std;

/*Runtime: 621 ms, faster than 14.52% of C++ online submissions for The k Strongest Values in an Array.
Memory Usage: 80.3 MB, less than 93.42% of C++ online submissions for The k Strongest Values in an Array.*/
class Solution {

public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        if(arr.size()<=k)return arr;
        sort(arr.begin(),arr.end());
        int m=arr[(arr.size()-1)/2];
        sort(arr.begin(),arr.end(),[m](auto x,auto y){
            if(abs(x-m)==abs(y-m))return x>y;
            return abs(x-m)>abs(y-m);
        });
        vector<int>ans(arr.begin(),arr.begin()+k);
        return ans;
    }
};