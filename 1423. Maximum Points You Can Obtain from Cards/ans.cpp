/*Runtime: 119 ms, faster than 17.57% of C++ online submissions for Maximum Points You Can Obtain from Cards.
Memory Usage: 42.4 MB, less than 80.56% of C++ online submissions for Maximum Points You Can Obtain from Cards.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int ans = 0,cur=0;;
        for(int i=0;i<k;i++){
            ans+=cardPoints[i];
        }
        cur =ans;
        for(int i=k-1;i>=0;i--){
            cur-=cardPoints[i];
            cur+=cardPoints[n-k+i];
            ans = max(cur,ans);
        }
        return ans;
    }
};



/*Two pointer*/
/*Runtime: 109 ms, faster than 25.45% of C++ online submissions for Maximum Points You Can Obtain from Cards.
Memory Usage: 42.5 MB, less than 48.14% of C++ online submissions for Maximum Points You Can Obtain from Cards*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int i=k-1;
        int j=n-1;

        int sum=0;
        for(int i=0;i<k;i++)sum+=cardPoints[i];

        int res=sum;
        while(i>=0){
            sum-=cardPoints[i];
            i--;
            sum+=cardPoints[j];
            j--;
            res=max(res,sum);
        }
        return res;
    }
};