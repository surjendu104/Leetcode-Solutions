class Solution
{
public:
    typedef long long ll;
    long long putMarbles(vector<int> &v, int k)
    {
        priority_queue<ll> pqmx;
        priority_queue<ll, vector<ll>, greater<ll>> pqmn;
        ll n = v.size();
        for (ll i = 0; i < n - 1; ++i)
        {
            pqmx.push(v[i] + v[i + 1]), pqmn.push(v[i] + v[i + 1]);
            if (pqmx.size() > k - 1)
            {
                pqmx.pop(), pqmn.pop();
            }
        }
        ll ans = 0;
        while (!pqmx.empty())
        {
            ans += pqmn.top() - pqmx.top();
            pqmx.pop(), pqmn.pop();
        }
        return ans;
    }
};

// Another approach
class Solution
{
public:
    long long putMarbles(vector<int> A, int k)
    {
        long long res = 0, n = A.size() - 1;
        for (int i = 0; i < n; ++i)
            A[i] += A[i + 1];
        A.pop_back();
        sort(A.begin(), A.end());
        for (int i = 0; i < k - 1; ++i)
            res += A[n - 1 - i] - A[i];
        return res;
    }
};