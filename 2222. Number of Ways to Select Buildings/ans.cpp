/*DP TLE*/
class Solution
{
public:
    long long f(string &s, int idx, int k, int prev, vector<vector<vector<long long>>> &dp)
    {
        if (k == 0)
            return 1;
        if (idx >= s.size())
            return 0;

        if (dp[idx][k][prev + 1] != -1)
            return dp[idx][k][prev + 1];

        if ((s[idx] - '0') != prev)
        {
            return dp[idx][k][prev + 1] = f(s, idx + 1, k - 1, s[idx] - '0', dp) + f(s, idx + 1, k, prev, dp);
        }
        else
        {
            return dp[idx][k][prev + 1] = f(s, idx + 1, k, prev, dp);
        }
    }
    long long numberOfWays(string s)
    {
        int n = s.size();
        // vector<vector<vector<long long>>>dp(n+1,vector<long long>(4,vector<long long>(4,-1)));
        vector<vector<vector<long long>>> dp;
        for (int i = 0; i < n + 1; i++)
        {
            vector<vector<long long>> t;
            for (int j = 0; j < 4; j++)
            {
                vector<long long> temp;
                for (int k = 0; k < 4; k++)
                {
                    temp.push_back(-1);
                }
                t.push_back(temp);
            }
            dp.push_back(t);
        }
        return f(s, 0, 3, -1, dp);
    }
};

/*Prefix sum :: Accepted*/
class Solution
{
public:
    long long numberOfWays(string s)
    {
        int n = s.size();
        vector<int> prez(n, 0), preo(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                prez[i] = (s[i] == '0') ? 1 : 0;
                preo[i] = (s[i] == '1') ? 1 : 0;
                continue;
            }
            prez[i] = prez[i - 1] + (s[i] == '0');
            preo[i] = preo[i - 1] + (s[i] == '1');
        }
        long long ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '1')
            {
                long long a = prez[i - 1];
                long long b = prez[n - 1] - prez[i];
                ans += (a * b);
            }
            else
            {
                long long a = preo[i - 1];
                long long b = preo[n - 1] - preo[i];
                ans += (a * b);
            }
        }
        return ans;
    }
};