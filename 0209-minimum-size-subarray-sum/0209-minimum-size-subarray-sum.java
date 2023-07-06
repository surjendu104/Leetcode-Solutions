class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length, j = 0;
        int len = Integer.MAX_VALUE, sum = 0;
        int i = 0;
        
        int check = 0;
        for(int x : nums)check+=x;
        if(check < target)return 0;
        
        while(j < n) {
            while(sum < target && j < n) {
                sum += nums[j];
                j++;
            }
            len = Math.min(len, j-i+1);
            System.out.println("dbg1 : "+len);
            while(sum >= target) {
                sum-=nums[i];
                i++;
            }
            len = Math.min(len, j-i+1);
            System.out.println("dbg1 : "+len);
        }
        return len;
    }
}