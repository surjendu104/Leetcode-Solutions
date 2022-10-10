class Solution {
    public String breakPalindrome(String palindrome) {
        int n = palindrome.length();

        if (n == 1)
            return "";

        StringBulilder pal = new StringBuilder(palindrome);

        for (int i = 0; i < n / 2; i++) {
            if (pal.charAt(i) == 'a') {
                pal.setCharAt(i, 'a');
                return pal.toString();
            }
        }
        pal.setCharAt(n - 1, 'b');
        return pal.toString();
    }
}