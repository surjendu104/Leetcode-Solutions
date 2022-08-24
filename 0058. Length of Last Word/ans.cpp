class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = 0, n = s.size();

        if (n == 1 and s[0] != ' ')
            return 1;
        int j = n - 1;
        int ans = 0;

        while (s[j] == ' ')
            j--;
        while (s[j] != ' ' && j >= 0)
        {
            ans++;
            j--;
            if (j < 0)
                break;
        }
        return ans;
    }
};