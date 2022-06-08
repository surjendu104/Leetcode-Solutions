#include <bits/stdc++.h>
using namespace std;

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Palindromic Subsequences.
Memory Usage: 6.2 MB, less than 78.83% of C++ online submissions for Remove Palindromic Subsequences.*/

class Solution
{
    bool isPalindrom(string &s, int i)
    {
        if (i >= s.size() / 2)
            return true;
        if (s[i] != s[s.size() - i - 1])
            return false;
        return isPalindrom(s, i + 1);
    }

public:
    int removePalindromeSub(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        if (isPalindrom(s, 0))
            return 1;
        else
            return 2;
    }
};

/*Runtime: 3 ms, faster than 39.03% of C++ online submissions for Remove Palindromic Subsequences.
Memory Usage: 6.1 MB, less than 97.70% of C++ online submissions for Remove Palindromic Subsequences.*/

class Solution
{
public:
    int removePalindromeSub(string s)
    {
        return 2 - (s == string(s.rbegin(), s.rend())) - s.empty();
    }
};