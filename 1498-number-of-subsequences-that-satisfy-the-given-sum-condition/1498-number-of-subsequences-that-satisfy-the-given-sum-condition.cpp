#define ll long long int

class Solution {
public:
    ll power(ll a, ll n, ll p) {
        ll ans = 1;
        while(n) {
            if(n%2) {
                ans = (ans*a)%p;
                n--;
            }else {
                a = (a*a)%p;
                n /= 2;
            }
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0, mod = 1000000007;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0, j = n-1; i <= j; ++i) {
            while(i <= j && nums[i]+nums[j]>target) {
                --j;
            }
            if(j >= i) {
                int tmp = (int)power(2, j-i, mod);
                ans = (ans+tmp)%mod;
            }
        }
        return ans;
    }
};