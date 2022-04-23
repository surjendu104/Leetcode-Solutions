class Solution
{
public:
    void generateP(int n, int o, int c, string s, vector<string> &v)
    {

        // if(o==n && c==n){
        //     v.push_back(s);
        //     return;
        // }

        if (s.length() == 2 * n)
        {
            v.push_back(s);
            return;
        }

        if (o < n)
        {
            generateP(n, o + 1, c, s + "(", v);
        }
        if (c < o)
        {
            generateP(n, o, c + 1, s + ")", v);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        generateP(n, 0, 0, "", ans);

        return ans;
    }
};