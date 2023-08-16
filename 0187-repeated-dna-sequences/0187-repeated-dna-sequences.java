class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        int k = 10;
        int i = 0, j = 0, n = s.length();
        Map<String, Integer> map = new HashMap<>();
        String str = "";
        while(j < n) {
            str = str+s.charAt(j);
            if(j-i+1 < k) j++;
            else if(j-i+1 == k) {
                map.put(str, 1+map.getOrDefault(str, 0));
                i++;
                j++;
                str = str.substring(1);
            }
        }

        List<String> res = new ArrayList<>();
        for(Map.Entry<String, Integer> m : map.entrySet()) {
            if(m.getValue() >= 2) res.add(m.getKey());
        }
        return res;
    }
}