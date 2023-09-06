class Solution {
    public int maxOperations(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        
        for(Integer val : nums) map.put(val, map.getOrDefault(val, 0)+1);
        
        int cnt = 0;
        for(Integer i : nums) {
            if(map.containsKey(k-i)) {
                if(2*i == k) {
                    cnt += Math.floor(map.get(i)/2);
                    map.remove(i);
                } 
                else {
                    cnt+= Math.min(map.get(i), map.get(k-i));
                    map.remove(i);
                    map.remove(k-i);
                }
            }
        }
        return cnt++;
    }
}