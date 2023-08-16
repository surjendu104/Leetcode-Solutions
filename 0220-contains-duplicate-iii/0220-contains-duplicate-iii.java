class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        int n = nums.length, j = 0;
        TreeSet<Long> set = new TreeSet<>();
        while(j < n) {
            Long floor = set.floor((long)nums[j]+valueDiff);
            Long ceil = set.ceiling((long)nums[j]-valueDiff);
            if((floor!=null && floor >= nums[j]) || (ceil != null && ceil <= nums[j])) return true;
            set.add((long)nums[j]);
            if(j >= indexDiff) set.remove((long)nums[j-indexDiff]);
            j++;
        }
        return false;
    }
}