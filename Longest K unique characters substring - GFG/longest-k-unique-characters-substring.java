//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GfG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            int k = sc.nextInt();
            Solution obj = new Solution();
            System.out.println(obj.longestkSubstr(s, k));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int longestkSubstr(String s, int k) {
        int n = s.length();
        int i = 0, j = 0;
        int len = 1;
        Map<Character, Integer> map = new HashMap<>();
        
        while(j < n) {
            Character c = s.charAt(j);
            map.put(c, 1+map.getOrDefault(c, 0));
            
            if(map.size() == k) len = Math.max(len, j-i+1);
            // else if(map.size() < k) j++;
            while(map.size() > k) {
                Character cc = s.charAt(i);
                map.put(cc, map.get(cc)-1);
                if(map.get(cc) == 0) map.remove(cc);
                i++;
            }
            j++;
        }
        return len;
    }
}