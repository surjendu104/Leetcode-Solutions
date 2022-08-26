class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string s = to_string(n);
        sort(s.begin(), s.end());
        for (int i = 0; i < 30; i++)
        {
            int num = pow(2, i);
            string x = to_string(num);
            sort(x.begin(), x.end());
            if (x == s)
            {
                // cout<<num<<endl;
                return true;
            }
        }
        return false;
    }
};