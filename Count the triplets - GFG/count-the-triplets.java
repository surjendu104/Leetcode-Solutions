//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            
            int n = Integer.parseInt(read.readLine());
            String input[] = read.readLine().split(" ");
            
            int arr[] = new int[n];
            for(int i = 0;i<n;i++){
                arr[i] = Integer.parseInt(input[i]);
            }
            
            Solution ob = new Solution();
            System.out.println(ob.countTriplet(arr, n));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    int countTriplet(int arr[], int n) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i : arr) map.put(i, 1+map.getOrDefault(i, 0));
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i != j) {
                    if(map.containsKey(arr[i]+arr[j])) ans++;
                }
            }
        }
        return ans/2;
    }
}