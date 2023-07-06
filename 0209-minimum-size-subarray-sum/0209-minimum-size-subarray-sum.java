class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length, j = 0;
        int len = Integer.MAX_VALUE, sum = 0;
        int i = 0;
        
        // If sum of array elements are less than target then return 0 because no subarray
        // will be exists that satisfy the condition
        int check = 0;
        for(int x : nums)check += x;
        if(check < target)return 0;
        
        while(j < n) {
            // Go to the index while sum less than target
            while(sum < target && j < n) {
                sum += nums[j];
                j++;
            }
            // find the minimum
            len = Math.min(len, j-i+1);
            // now when sum greater than target then shrink the window and check for minimum window
            while(sum >= target) {
                sum-=nums[i];
                i++;
            }
            // get the minimum satisfying window
            len = Math.min(len, j-i+1);
        }
        return len;
    }
}