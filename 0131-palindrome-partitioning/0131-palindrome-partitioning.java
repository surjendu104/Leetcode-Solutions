class Solution {
    static boolean isPalindrome(int i, int j, String s) {
        while(i <= j) {
            if(s.charAt(i) != s.charAt(j)) return false;
            i++;j--;
        }
        return true;
    }
    void solve(int idx, String s, List<String> ds, List<List<String>> ans) {
        if(idx == s.length()) {
            ans.add(new ArrayList<>(ds));
            return;
        }

        for(int i = idx; i < s.length(); ++i) {
            if(isPalindrome(idx, i, s)) {
                String ss = s.substring(idx, i+1);
                ds.add(ss);
                solve(i+1, s, ds, ans);
                ds.remove(ds.size()-1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> lis = new ArrayList<>();
        List<String> ds = new ArrayList<>();
        solve(0, s, ds, lis);
        return lis;
    }
}