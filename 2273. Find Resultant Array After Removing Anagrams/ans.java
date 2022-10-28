
class Solution {
    // function for checking if two string are anagrams or not
    boolean isang(String p, String q) {
        int[] cnt = new int[26];
        int res = 0;
        for (int i = 0; i < p.length(); i++)
            cnt[p.charAt(i) - 'a']++;
        for (int i = 0; i < q.length(); i++)
            cnt[q.charAt(i) - 'a']--;
        for (int i : cnt)
            if (i != 0)
                return false;
        return true;
    }

    public List<String> removeAnagrams(String[] A) {
        List<String> ans = new ArrayList<>();
        int n = A.length;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && isang(A[i], A[j]))
                j++;
            ans.add(A[i]);
            i = j;
        }
        return ans;
    }
}