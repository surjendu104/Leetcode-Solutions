//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])throws IOException
        {
            BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());
            while(t-->0)
                {
                    String arr[] = br.readLine().split(" ");
                    String A = arr[0];
                    String B = arr[1];
                    Solution obj = new Solution();
                    System.out.println(obj.transform (A, B));
                }
        }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    int transform (String A, String B)
    {
        // code here
        int n = A.length(), m = B.length();
        
        if(n != m) return -1;
        
        Map<Character, Integer> map = new HashMap<>();
        for(Character c : A.toCharArray()) map.put(c, 1+ map.getOrDefault(c, 0));
        for(Character c : B.toCharArray()) {
            if(map.containsKey(c)) map.put(c, map.get(c) - 1);
        }
        for(Map.Entry<Character, Integer> ele : map.entrySet()) {
            if(ele.getValue() != 0) return -1;
        }
        
        int i = n-1, j = m-1;
        int ans = 0;
        while(i >= 0 && j >= 0) {
            while(i >= 0 && A.charAt(i) != B.charAt(j)) {
                ans++;
                i--;
            }
            i--;
            j--;
        }
        return ans;
    }
}