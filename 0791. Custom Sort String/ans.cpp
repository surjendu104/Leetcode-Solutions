
#include<bits/stdc++.h>
using namespace std;

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Custom Sort String.
Memory Usage: 6.3 MB, less than 31.42% of C++ online submissions for Custom Sort String.*/
class Solution {
  public:
    string customSortString(string order, string s) {

      unordered_map < char, int > mp;
      for (auto a: s) {
        mp[a]++;
      }

      string str = "";
      for (auto a: order) {

        while (mp[a]) {
          str += a;
          mp[a]--;

        }
      }

      for (auto a: s) {
        if (mp[a])
          str += a;
      }
      return str;
    }
};
