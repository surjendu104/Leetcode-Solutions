class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mp1, mp2;
        for (int i : ransomNote)
            mp1[i]++;
        for (int i : magazine)
            mp2[i]++;

        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (mp2.find(ransomNote[i]) != mp2.end())
            {
                if (mp2[ransomNote[i]] < mp1[ransomNote[i]])
                {
                    return false;
                }
            }
            else
                return false;
        }
        return true;
    }
};

// 2
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int mp[26] = {0};
        for (auto c : magazine)
        {
            mp[c - 'a']++;
        }
        for (auto r : ransomNote)
        {
            mp[r - 'a']--;
            if (mp[r - 'a'] < 0)
                return false;
        }
        return true;
    }
};