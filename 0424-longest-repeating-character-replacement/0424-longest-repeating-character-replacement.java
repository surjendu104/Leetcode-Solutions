class Solution {
    public int characterReplacement(String s, int k) {
        int i = 0, j = 0, n = s.length();
        int len = Integer.MIN_VALUE;
        HashMap<Character, Integer> map = new HashMap<>();
        
        while(j < n) {
            char c = s.charAt(j);
            map.put(c, 1 + map.getOrDefault(c, 0));
            len = Math.max(len, map.get(c));
            
            while(j-i+1-len > k) {
                char cc = s.charAt(i);
                map.put(cc, map.get(cc)-1);
                i++;
            }
            j++;
        }
        return n-i;
    }
}