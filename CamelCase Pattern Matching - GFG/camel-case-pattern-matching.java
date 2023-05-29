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
            int N = Integer.parseInt(read.readLine());
            String[] Dictionary=read.readLine().split(" ");
            String Pattern=read.readLine();
            Solution ob = new Solution();
            ArrayList <String> ans=ob.CamelCase(N,Dictionary,Pattern);
            for(String u:ans)
             System.out.print(u+" ");
            System.out.println(); 
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    ArrayList<String> CamelCase(int N,String[] Dictionary,String Pattern){
        //code here
        ArrayList<String> ans = new ArrayList<String>();
        for(String s : Dictionary) {
            String upper = s.chars()
                            .filter(c -> c > 64 && c < 97)
                            .collect(StringBuilder::new,
                                     (sb, c) -> sb.append((char) c),
                                     (sb1, sb2) -> sb1.append(sb2.toString()))
                            .toString();
            // System.out.println("dbg : "+upper);
            if(upper.contains(Pattern) && upper.indexOf(Pattern) == 0) {
                ans.add(s);
            }
        }
        if(ans.size()==0){
            ans.add("-1");
        };
        Collections.sort(ans);
        return ans;
    }
}