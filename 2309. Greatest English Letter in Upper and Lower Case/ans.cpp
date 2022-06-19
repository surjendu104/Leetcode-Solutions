class Solution
{
public:
    string greatestLetter(string s)
    {

        unordered_map<char, int> mpp;
        // transform(s.begin(),s.end(),s.begin(),::toupper);
        for (int i = 0; i < s.size(); ++i)
        {
            mpp[s[i]]++;
        }
        string ans = "";
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); ++i)
        {
            int l = tolower(s[i]);
            int u = toupper(s[i]);

            if (mpp[l] && mpp[u])
            {
                ans = u;
            }
        }
        return ans;
    }
};