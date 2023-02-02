class Solution
{
public:
    bool check(unordered_map<char, int> mpp, string word1, string word2)
    {
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size())
        {
            if (mpp[word1[i]] > mpp[word2[j]])
                return false;
            else if (mpp[word1[i]] < mpp[word2[j]])
                return true;
            i++;
            j++;
        }

        return (word1.size() <= word2.size());
    }

    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> mpp;
        int pos = 0;
        for (char i : order)
        {
            mpp[i] = pos;
            pos++;
        }

        for (int i = 0; i + 1 < words.size(); i++)
        {
            if (!check(mpp, words[i], words[i + 1]))
                return false;
        }
        return true;
    }
};