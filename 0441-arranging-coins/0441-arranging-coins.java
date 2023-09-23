class Solution {
    public int arrangeCoins(int n) {
        int l = 1, r = n;
        int ans = 1;
        while(l <= r) {
            int mid = l +(r-l)/2;
            long x = mid*((long)mid+1)/2;
            if(x <= n) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
}