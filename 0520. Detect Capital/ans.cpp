class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        bool f1 = true, f2 = true;

        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] < 65 or word[i] > 90)
            {
                f1 = false;
                break;
            }
        }
        if ((word[0] >= 65 and word[0] <= 90) || (word[0] >= 97 and word[0] <= 122))
        {
            for (int i = 1; i < word.size(); i++)
            {
                if (word[i] < 97 or word[i] > 122)
                {
                    f2 = false;
                    break;
                }
            }
        }
        return f1 | f2;
    }
};