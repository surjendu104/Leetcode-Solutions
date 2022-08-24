class Solution {
    public boolean isPowerOfThree(int n) {
        return n != 0 && Math.pow(3, Math.round(Math.log(n) / Math.log(3))) == n;
    }
}

class Solution {
    public boolean isPowerOfThree(int n) {
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        if (n % 3 == 0) {
            while (n >= 3 && n % 3 == 0)
                n /= 3;
            if (n == 1)
                return true;
            return false;
        } else
            return false;
    }
}