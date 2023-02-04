class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;
        sort(s1.begin(), s1.end());

        for (int i = 0; i <= s2.size() - s1.size(); i++)
        {
            string str = s2.substr(i, s1.size());
            sort(str.begin(), str.end());
            if (str == s1)
                return true;
        }
        return false;
    }
};

// Approach - 2
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        if (s1.size() > s2.size())
            return false;

        vector<int> f1(26, 0), f2(26, 0);
        for (char c : s1)
            f1[c - 'a']++;

        int k = s1.size();
        for (int i = 0; i < k - 1; i++)
            f2[s2[i] - 'a']++;

        for (int i = k - 1; i < s2.size(); i++)
        {
            f2[s2[i] - 'a']++;
            if (f1 == f2)
                return true;
            f2[s2[i - (k - 1)] - 'a']--;
        }
        return false;
    }
};

// Approach - 3
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        vector<int> f1(26, 0);
        vector<int> f2(26, 0);

        int n = s1.size(), m = s2.size();
        if (m < n)
            return false;

        int left = 0, right = 0;
        while (right < n)
        {
            f1[s1[right] - 'a'] += 1;
            f2[s2[right] - 'a'] += 1;
            right += 1;
        }
        right -= 1;
        while (right < m)
        {
            if (f1 == f2)
                return true;

            right += 1;
            if (right != m)
                f2[s2[right] - 'a'] += 1;
            f2[s2[left] - 'a'] -= 1;
            left += 1;
        }
        return false;
    }
};