class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int n = s.size();
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[n - 1 - i])
                return false;
        }
        return true;
    }
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.size();
        if (n == 1)
            return "";

        for (int i = 0; i < n; i++)
        {
            if (palindrome[i] != 'a')
            {
                char x = palindrome[i];
                palindrome[i] = 'a';
                if (isPalindrome(palindrome))
                {
                    palindrome[i] = x;
                    break;
                }
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};