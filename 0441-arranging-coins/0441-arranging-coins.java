class Solution {
    public int arrangeCoins(int n) {
        int cnt = 0;
        int i = 0;
        while(n >= i) {
            n-=i;
            cnt++;
            i++;
        }
        return cnt-1;
    }
}