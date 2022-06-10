#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> m(256, -1);
        int left = 0, right = 0, len = 0, n = s.size();

        while (right < n)
        {
            if (m[s[right]] != -1)
                left = max(m[s[right]] + 1, left);

            m[s[right]] = right;

            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};

/*Runtime: 38 ms, faster than 34.51% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 13.4 MB, less than 15.71% of C++ online submissions for Longest Substring Without Repeating Characters.*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int ans=0,i=0,j=0,n=s.size();

        while(j<n){
            if(st.count(s[j])==0){
                st.insert(s[j]);
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                st.erase(s[i]);i++;
            }
        }
        return ans;
    }
};