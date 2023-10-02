//{ Driver Code Starts
import java.util.Scanner;
import java.util.*;

class GFG
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t =sc.nextInt();
		while(t>0)
		{
			int n = sc.nextInt();
			int arr[] = new int[n];
			for(int i=0;i<n;i++)
				arr[i] = sc.nextInt();
			Solution ob = new Solution();
			System.out.println(ob.maxDistance(arr,n));
		
		t--;
		}
	}
}
// } Driver Code Ends


// your task is to complete this function
class Solution
{
    int maxDistance(int arr[], int n)
    {
    	Map<Integer, int[]> map = new HashMap<>();
    	for(int i = 0; i < n; ++i) {
    	    if(map.containsKey(arr[i])) {
    	        int[] nums = map.get(arr[i]);
    	        nums[1] = i;
    	        map.put(arr[i], nums);
    	    }
    	    else {
    	        int[] nums = new int[2];
    	        Arrays.fill(nums, -1);
    	        nums[0] = i;
    	        map.put(arr[i], nums);
    	    }
    	}
    	int maxi = Integer.MIN_VALUE;
    	for(Map.Entry<Integer, int[]> ele : map.entrySet()) {
    	    int[] nums = ele.getValue();
    	    if(nums[1] != -1) maxi = Math.max(maxi, nums[1] - nums[0]);
    	}
    	return maxi == Integer.MIN_VALUE ? 0 : maxi;
    }
}
