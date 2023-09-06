class Solution {
    public int countKDifference(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        int cnt = 0;
        for(Integer i : nums) {
            if(map.containsKey(i-k)) {
                cnt += map.get(i-k);
            }if(map.containsKey(i+k)) {
                cnt +=map.get(i+k);
            }
            map.put(i, 1+map.getOrDefault(i, 0));
        }
        
        return cnt;
    }
}