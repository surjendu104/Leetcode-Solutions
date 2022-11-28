class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> v;
        unordered_map<int, int> mp1, mp2;
        set<int> st;
        for (auto i : matches)
        {
            mp1[i[0]]++;
            mp2[i[1]]++;
        }
        for (auto i : matches)
        {
            if (mp2.find(i[0]) == mp2.end())
                st.insert(i[0]);
        }
        vector<int> a(st.begin(), st.end());
        st.clear();
        for (auto i : matches)
        {
            if (mp2[i[1]] == 1)
                st.insert(i[1]);
        }
        vector<int> b(st.begin(), st.end());
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};