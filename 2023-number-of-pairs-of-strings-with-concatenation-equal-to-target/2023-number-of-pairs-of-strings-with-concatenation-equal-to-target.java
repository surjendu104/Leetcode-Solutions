class Solution {
    public int numOfPairs(String[] nums, String target) {
        int n = target.length();
        Map<String, Integer> map = new HashMap<>();
        for(String i : nums) map.put(i, 1+map.getOrDefault(i, 0));
        
        int cnt = 0;
        for(int i = 1; i < n; ++i) {
            String a = target.substring(0, i);
            String b = target.substring(i);
            if(map.containsKey(a) && map.containsKey(b)) {
                if(a.equals(b)) cnt += (map.get(a)*(map.get(a)-1));
                else cnt+= map.get(a)*map.get(b);
            }
        }
        return cnt;
    }
}