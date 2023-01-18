class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int maxSubarraySum = Integer.MIN_VALUE, currMaxSubarraySum = 0;
        int minSubarraySum = Integer.MAX_VALUE, currMinSubarraySum = 0;
        int totalSum = 0;

        for (int i : nums) {
            currMaxSubarraySum = Math.max(i, currMaxSubarraySum + i);
            maxSubarraySum = Math.max(maxSubarraySum, currMaxSubarraySum);
            currMinSubarraySum = Math.min(i, currMinSubarraySum + i);
            minSubarraySum = Math.min(minSubarraySum, currMinSubarraySum);
            totalSum += i;
        }
        return (maxSubarraySum > 0 ? Math.max(maxSubarraySum, totalSum - minSubarraySum) : maxSubarraySum);
    }
}