class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), i = 0, j = 0;
        if(n == 0) return 0;
        int len = 1;
        HashSet<Character> set = new HashSet<>();
        
        while(j < n) {
            char c = s.charAt(j);
            while(set.contains(c)) {
                set.remove(s.charAt(i));
                i++;
            }
            set.add(s.charAt(j));
            len = Math.max(len, set.size());
            j++;
        }
        return len;
    }
}