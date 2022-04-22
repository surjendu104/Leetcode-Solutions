class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> m(256, -1);
        int left = 0, right = 0, len = 0, n = s.size();

        while (right < n)
        {
            if (m[s[right]] != -1)
                left = max(m[s[right]] + 1, left);

            m[s[right]] = right;

            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};