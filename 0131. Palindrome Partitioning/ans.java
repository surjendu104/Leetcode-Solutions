

class Solution {
    boolean checkPalindrome(int start, int end, String s) {
        while (start <= end) {
            if (s.charAt(start) != s.charAt(end))
                return false;
            start++;
            end--;
        }
        return true;
    }

    void helper(int idx, String s, List<String> ds, List<List<String>> ans) {
        if (idx == s.length()) {
            ans.add(new ArrayList<>(ds));
            return;
        }

        for (int i = idx; i < s.length(); i++) {
            if (checkPalindrome(idx, i, s) == true) {
                String str = s.substring(idx, i + 1);
                ds.add(str);
                helper(i + 1, s, ds, ans);
                ds.remove(ds.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        List<String> ds = new ArrayList<>();
        helper(0, s, ds, ans);
        return ans;
    }
}