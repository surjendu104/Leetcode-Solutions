#include<bits/stdc++.h>
using namespace std;

//TLE :: Bruth force
class Solution {
public:
    int minStoneSum(vector<int>& p, int k) {
        int n = p.size()-1;
        while(k--) {
            sort(p.begin(),p.end());
            float x = (float)p[n]/2;
            p[n] = round(x);
        }
        int ans = accumulate(p.begin(),p.end(),0);
        return ans;
    }
};

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i:piles)pq.push(i);
        
        while(k--) {
            int x = pq.top();
            pq.pop();
            pq.push(x-x/2);
        }

        int ans = 0;
        while(pq.size()) {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};