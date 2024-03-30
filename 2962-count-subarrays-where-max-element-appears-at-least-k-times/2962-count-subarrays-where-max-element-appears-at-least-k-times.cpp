#define ll long long
class Solution {
public:
    ll countSubarraysWithAtLeastKOccurrences(const vector<int>& arr, int x, int k) {
        ll n = arr.size();
        ll count = 0;

        unordered_map<ll, ll> map;
        ll i = 0;
        ll cnt = 0;

        for (ll j = 0; j < n; ++j) {
            if (arr[j] == x) {
                cnt++;
            }
            map[arr[j]]++;

            while (cnt >= k) {
                count += (n - j);

                
                if (arr[i] == x) {
                    cnt--;
                }
                map[arr[i]]--;
                if (map[arr[i]] == 0) {
                    map.erase(arr[i]);
                }

                i++;
            }
        }

        return count;
    }

    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        ll cnt = 0;
        ll c = 0;
        int mx = *max_element(begin(nums), end(nums));
        cnt = countSubarraysWithAtLeastKOccurrences(nums, mx, k);
        return cnt;
    }
};
