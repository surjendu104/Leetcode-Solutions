class Solution
{
public:
    int partitionString(string s)
    {
        unordered_set<char> st;
        int ans = 0;
        for (char i : s)
        {
            if (st.count(i) != 0)
            {
                st.clear();
                ans++;
            }
            st.insert(i);
        }
        return ans + 1;
    }
};