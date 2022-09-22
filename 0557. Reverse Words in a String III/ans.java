class Solution {
    public String reverseWords(String s) {
        int l = 0, r = 0, n = s.length();
        char[] c = s.toCharArray();
        for (int i = 0; i < n; i++) {
            if (c[i] == ' ' || i == n - 1) {
                r = i == n - 1 ? i : i - 1;
                while (l < r) {
                    char tmp = c[l];
                    c[l] = c[r];
                    c[r] = tmp;
                    l++;
                    r--;
                }
                l = i + 1;
            }
        }
        return new String(c);
    }
}