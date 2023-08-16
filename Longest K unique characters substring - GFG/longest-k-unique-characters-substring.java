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
        Map<Character, Integer> map = new HashMap<>();
        int i = 0, j = 0, n = s.length();
        int len = Integer.MIN_VALUE;
        while(j < n) {
            char c = s.charAt(j);
            map.put(c, 1+map.getOrDefault(c, 0));
            if(map.size() < k) j++;
            else if(map.size() == k) {
                len = Math.max(len, j-i+1);
                j++;
            }else if(map.size() > k) {
                char cc = s.charAt(i);
                map.put(cc, map.get(cc)-1);
                i++;
                j++;
                if(map.get(cc) == 0)map.remove(cc);
            }
        }
        return len!=Integer.MIN_VALUE?len:-1;
    }
}