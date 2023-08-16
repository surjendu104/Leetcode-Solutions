class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        int i = 0, j = 0, n = nums.length;
        Set<Integer> st = new HashSet<>();
        while(j < n) {
            if(j > k) {
                st.remove(nums[j-k-1]);
            }
            if(!st.add(nums[j])) return true;
            j++;
        }
        return false;
    }
}