class Solution
{
public:
    bool isPalindrome(string s)
    {
        string a;
        for (char x : s)
        {
            if (isalpha(x) || isdigit(x))
                a += x;
        }
        for_each(a.begin(), a.end(), [](char &c)
                 { c = tolower(c); });
        // cout<<a<<endl;

        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != a[a.length() - 1 - i])
                return false;
        }
        return true;
    }
};