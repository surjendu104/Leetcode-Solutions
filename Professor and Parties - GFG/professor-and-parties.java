//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
	        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while(t-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            long a[] = new long[(int)(n)];
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(inputLine[i]);
            }
            
            Solution obj = new Solution();
            System.out.println(obj.PartyType(a, n));
            
        }
	}
}

// } Driver Code Ends


//User function Template for Java


class Solution {

    public static String PartyType( long a[], int n)
    {
        Set<Long> set = new HashSet<>();
        for(Long ele : a) {
            if(set.contains(ele)) return "BOYS";
            set.add(ele);
        }
        return "GIRLS";
    }
}