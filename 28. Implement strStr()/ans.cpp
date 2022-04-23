class Solution
{
public:
    int strStr(string n, string m)
    {
        int a = m.size();

        if (n.size() < a)
            return -1;
        for (int idx = 0; idx <= n.size() - a; idx++)
        {
            if (string(n.begin() + idx, n.begin() + idx + a) == m)
                return idx;
        }
        return -1;
    }
};