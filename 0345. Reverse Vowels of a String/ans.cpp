class Solution
{
public:
    bool isVowel(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s)
    {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            while (l < n && !isVowel(s[l]))
                l++;
            while (r >= 0 && !isVowel(s[r]))
                r--;
            if (l < r)
            {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};