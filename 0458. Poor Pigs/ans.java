class Solution {
    public int poorPigs(int buckets, int mi, int mt) {
        int period = mt / mi + 1;
        int ans = 0;
        while(Math.pow(period, ans) < buckets)
        {
            ans ++;
        }
        return ans;
    }
}