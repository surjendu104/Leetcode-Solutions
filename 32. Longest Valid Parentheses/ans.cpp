class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.length(), res = 0;
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }

            else
            {
                if (!st.empty())
                {
                    st.pop();
                }

                if (!st.empty())
                    res = max(res, i - st.top());
                else
                {
                    st.push(i);
                }
            }
        }
        return res;
    }
};