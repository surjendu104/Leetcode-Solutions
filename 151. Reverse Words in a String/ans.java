class Solution {
    void reverse(String a[], int n)
    {
        int i, k;
        String t;
        for (i = 0; i < n / 2; i++) {
            t = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = t;
        }
    }
    public String reverseWords(String s) {
        String[] str = s.split(" +");
        reverse(str,str.length);
        String ans = "";
        for(String c:str){
            ans+=c;
            ans+=" ";
        }
        return ans.trim();
    }
}