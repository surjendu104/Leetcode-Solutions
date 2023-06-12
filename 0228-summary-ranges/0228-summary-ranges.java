class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ans = new ArrayList<String>();
        int n = nums.length;
        int i = 0;
        while(i < n) {
            String s = Integer.toString(nums[i]);
            int j = i;
            for(j = i; j < n-1 && nums[j] + 1 == nums[j+1]; j++){}
            if(i != j)s+="->" + Integer.toString(nums[j]);
            
            j++;
            i = j;
            ans.add(s);
            s = "";
        }
        return ans;
    }
}