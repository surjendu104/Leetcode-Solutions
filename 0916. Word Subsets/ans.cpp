class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> ans;
        vector<int> v(26);
        for (string s : words2)
        {
            vector<int> a(26);
            for (char c : s)
                a[c - 'a']++;
            for (int i = 0; i < 26; i++)
                v[i] = max(v[i], a[i]);
        }

        int f = 1;
        for (string s : words1)
        {
            vector<int> a(26);
            for (char c : s)
                a[c - 'a']++;
            int f = 1;
            for (int i = 0; i < 26; i++)
            {
                if (v[i] > a[i])
                {
                    f = 0;
                    break;
                }
            }
            if (f)
                ans.push_back(s);
        }
        return ans;
    }
};

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        int sub[26] = {0}, temp[26] = {0};
        vector<string> res;

        for (const string &s : words2)
        {
            for (int i = 0; i < s.size(); i++)
                temp[s[i] - 'a']++;
            for (int j = 0; j < 26; j++)
                sub[j] = max(sub[j], temp[j]);
            memset(temp, 0, 104);
        }

        for (const string &s : words1)
        {
            copy(begin(sub), end(sub), begin(temp));
            for (int i = 0; i < s.size(); i++)
                temp[s[i] - 'a']--;
            int k = 0;
            while (k < 26)
                if (temp[k++] > 0)
                    break;
            if (k == 26)
                res.push_back(s);
        }

        return res;
    }
};