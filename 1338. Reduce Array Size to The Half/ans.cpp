#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        set<int>st;
        for(int i:arr)mp[i]++;
        int c=0;
        for(auto x:mp){
            cout<<x.first<<" "<<x.second<<endl;
        }
        for(auto x:mp){
            if(c<n/2){
                c+=x.second-1;   
                st.insert(x.first);
            }else{
                break;
            }
        }
        for(auto i:st)cout<<i<<" ";
        cout<<endl;
        return st.size();
    }
};

class Solution{
    public:
        int minSetSize(vector<int>& arr){
            int n=arr.size();
            vector<int>freq(1000005,0);
            for(int i:arr)freq[i]++;

            sort(freq.begin(),freq.end(),greater<int>());

            int ans=0;
            int c=0;
            for(int i=0;i<n and c<n/2;i++){
                c+=freq[i];
                ans++;
            }
            return ans;
        }
};