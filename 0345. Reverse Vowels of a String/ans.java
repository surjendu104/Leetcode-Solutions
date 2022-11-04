class Solution {
    public boolean isVowel(char c) {
        c = Character.toLowerCase(c);
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    public String reverseVowels(String s) {
        int n = s.length();
        int l = 0,r = n-1;
        char[] ans = s.toCharArray();
        while(l<r) {
            while(l<n && !isVowel(ans[l]))l++;
            while(r>=0 && !isVowel(ans[r]))r--;
            if(l<r){
                char temp = ans[l];
                ans[l] = ans[r];
                ans[r] = temp;
                l++;r--;
            }
        }
        return new String(ans);
    }
}