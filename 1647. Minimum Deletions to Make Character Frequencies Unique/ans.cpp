/*Runtime: 217 ms, faster than 8.32% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.
Memory Usage: 17.6 MB, less than 14.17% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.*/

class Solution
{
public:
    int minDeletions(string s)
    {
        int n = s.size();
        unordered_map<char, int> mp;
        for (char x : s)
            mp[x]++;
        int c = 0;
        vector<int> v;
        for (auto i : mp)
        {
            v.push_back(i.second);
        }
        // sort(v.begin(),v.end(),[&](int x,int y){
        //     return x>y;
        // });
        sort(v.begin(), v.end(), greater<int>());
        unordered_set<int> st;
        for (int i = 0; i < v.size(); ++i)
        {
            while (v[i] > 0 && st.count(v[i]))
            {
                v[i]--;
                c++;
            }
            st.insert(v[i]);
        }
        return c;
    }
};