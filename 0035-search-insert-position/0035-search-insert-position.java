class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length;
        
        while(l < r) {
            int mid = l + (r-l) / 2;
            if(target <= nums[mid]) r = mid;
            else l = mid+1;
            
            if(l < nums.length && nums[l] < target) l++;
        }
        return l;
    }
}