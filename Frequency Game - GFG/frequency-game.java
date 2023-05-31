//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.io.*;

// Position this line where user code will be pasted.

// Driver class with main function
class GFG {
    // Main function
    public static void main(String[] args)throws IOException {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());

        // Iterating over testcases
        while (t-- > 0) {
            int n = Integer.parseInt(in.readLine());
            int arr[] = new int[n];

            String s[]=in.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(s[i]);

            Solution obj = new Solution();
            System.out.println(obj.LargButMinFreq(arr, n));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

// Helper class to find largest number with minimum frequency
class Solution {
    // Function to find largest number with minimum frequency
    public static int LargButMinFreq(int arr[], int n) {
        // Your code here
        
        int min_frq = Integer.MAX_VALUE, ans = Integer.MIN_VALUE;
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int i : arr) {
            if(map.containsKey(i))map.put(i,map.get(i)+1);
            else map.put(i, 1);
        }
        for(Map.Entry<Integer, Integer> it : map.entrySet()) {
            min_frq = Math.min(min_frq, it.getValue());
        }
        for(Map.Entry<Integer, Integer> it : map.entrySet()) {
            if(it.getValue()==min_frq)ans = Math.max(ans, it.getKey());
        }
        
        return ans;
    }
}