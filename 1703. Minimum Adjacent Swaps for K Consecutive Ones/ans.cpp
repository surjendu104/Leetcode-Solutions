#define ll long long
class Solution
{
public:
    int minMoves(vector<int> &nums, int k)
    {
        int n = nums.size(), l, r;
        vector<ll> v;
        v.push_back(0);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                v.push_back(i);
        }
        n = v.size();
        vector<ll> psum(n, 0);
        for (int i = 1; i < n; i++)
        {
            psum[i] = v[i] + psum[i - 1];
        }

        ll ans = 1e18;

        for (l = 1, r = k; r < n; ++l, ++r)
        {
            int mid = (l + r) / 2;
            int radius = mid - l;
            ll blue = psum[mid - 1] - psum[l - 1];
            ll red = psum[r] - psum[mid];
            ll last = (radius + 1) * radius;

            if (k % 2 == 0)
            {
                blue += v[mid];
                last += (radius + 1);
            }
            ans = min(ans, red - blue - last);
        }
        return ans;
    }
};