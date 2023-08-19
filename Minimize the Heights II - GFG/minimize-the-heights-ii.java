//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

  public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int k = Integer.parseInt(inputLine[0]);
            inputLine = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().getMinDiff(arr, n, k);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    int getMinDiff(int[] arr, int n, int k) {
        Arrays.sort(arr);
        int ans = arr[n-1] - arr[0];
        
        int maxi = arr[n-1]-k;
        int mini = arr[0]+k;
        int mx, mi;
        for(int i = 0; i < n-1; ++i) {
            mx = Math.max(maxi, arr[i]+k);
            mi = Math.min(mini, arr[i+1]-k);
            if(mi < 0) continue;
            ans = Math.min(ans, mx-mi);
        }
        return ans;
    }
}
