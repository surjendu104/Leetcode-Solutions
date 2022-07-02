#include <bits/stdc++.h>
using namespace std;

/*Runtime: 90 ms, faster than 72.84% of C++ online submissions for Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.
Memory Usage: 32.3 MB, less than 40.04% of C++ online submissions for Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts*/

class Solution
{
public:
    int maxArea(int h, int w, vector<int> &hc, vector<int> &vc)
    {
        int mod = 1e9 + 7;
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());

        hc.push_back(h);
        vc.push_back(w);
        int hmax = hc[0], vmax = vc[0];

        for (int i = 1; i < hc.size(); ++i)
        {
            hmax = max(hmax, hc[i] - hc[i - 1]);
        }

        for (int i = 1; i < vc.size(); ++i)
        {
            vmax = max(vmax, vc[i] - vc[i - 1]);
        }

        return (int)((long)hmax * vmax % mod);
    }
};