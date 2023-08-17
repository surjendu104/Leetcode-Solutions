class Solution {
    public String minWindow(String s, String t) {
        int i = 0, j = 0, n = s.length(), len = Integer.MAX_VALUE, start = 0;
        HashMap<Character, Integer> map1 = new HashMap<>();
        HashMap<Character, Integer> map2 = new HashMap<>();
        for(char c : t.toCharArray()) map1.put(c, 1+map1.getOrDefault(c, 0));
        int need = 0;

        while(j < n) {
            char c = s.charAt(j);
            if(map1.containsKey(c)){
                map2.put(c, 1+ map2.getOrDefault(c, 0));
                if(map2.get(c).equals(map1.get(c))) need++;
            }
            while(need == map1.size()) {
                if(len > j-i+1) {
                    len = j-i+1;
                    start = i;
                }
                char cc = s.charAt(i);
                if(map1.containsKey(cc)) {
                    if(map2.get(cc).equals(map1.get(cc))) need--;
                    map2.put(cc, map2.get(cc)-1);
                }
                i++;
            }
            j++;
        }
        return len == Integer.MAX_VALUE ? "" : s.substring(start, start+len);
    }
}