class Solution {
    public int minIncrementForUnique(int[] nums) {
        int ans = 0, need = 0;
        Arrays.sort(nums);
        for (int i : nums) {
            ans += Math.max(need - i, 0);
            need = Math.max(i, need) + 1;
        }
        return ans;
    }
}