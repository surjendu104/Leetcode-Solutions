//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            String s = br.readLine().trim();
            String[] s1 = s.split(" ");
            int[] nums = new int[n];
            for(int i = 0; i < s1.length; i++)
                nums[i] = Integer.parseInt(s1[i]);
            Solution ob = new Solution();
            int ans = ob.LongestBitonicSequence(nums);
            System.out.println(ans);           
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    int[] LIS(int[] a, int n) {
        int[] dp = new int[n];
        
        for(int i = 0; i < n; ++i) {
            dp[i] = 1;
            for(int j = 0; j < i; ++j) {
                if(a[i] > a[j]) dp[i] = Math.max(dp[i], 1+dp[j]);
            }
        }
        return dp;
    }
    public int LongestBitonicSequence(int[] nums)
    {
        int n = nums.length;
        int[] dp1 = LIS(nums, n);
        
        int[] tmp = new int[n];
        for(int i = n-1; i >= 0; --i) {
            tmp[n-i-1] = nums[i];
        }
        int[] arr = LIS(tmp, n);
        int[] dp2 = new int[n];
        for(int i = n-1; i >= 0; --i) dp2[n-i-1] = arr[i];
        
        int ans = Integer.MIN_VALUE;
        for(int i = 0; i < n; ++i) ans = Math.max(ans, dp1[i]+dp2[i]-1);
        return ans;
    }
}