class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n+1];
        int[] hash = new int[n+1];
        int lastIndex = 0, maxi = Integer.MIN_VALUE;
        
        Arrays.fill(dp, 1);
        Arrays.sort(nums);
        for(int i = 0; i < n; ++i) hash[i] = i;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] % nums[j] == 0 && dp[i] < 1+dp[j]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        List<Integer> ans = new ArrayList<>();
        ans.add(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            ans.add(nums[lastIndex]);
        }
        return ans;
    }
}