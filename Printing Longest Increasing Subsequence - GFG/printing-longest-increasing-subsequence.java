//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG{
    public static void main(String args[]) throws IOException{
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            int N=sc.nextInt();
            int []arr=new int[N];
            for(int i=0;i<N;i++){
                arr[i]=sc.nextInt();
            }
            Solution obj=new Solution();
            ArrayList<Integer>ans=obj.longestIncreasingSubsequence(N, arr);
            for(int i=0;i<ans.size();i++){
                System.out.print(ans.get(i)+" ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    public ArrayList<Integer> longestIncreasingSubsequence(int N, int arr[]){
        int[] dp = new int[N+1];
        int[] map = new int[N+1];
        int lastIndex = 0, maxi = Integer.MIN_VALUE;

        Arrays.fill(dp, 1);
        for(int i = 0; i < N; ++i) map[i] = i;

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < i; ++j) {
                if(arr[j] < arr[i] && 1+dp[j] > dp[i]) {
                    dp[i] = 1+dp[j];
                    map[i] = j;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        // for(int i : map)System.out.print(i+" ");
        // System.out.println();
        
        ArrayList<Integer> res = new ArrayList<>();
        res.add(arr[lastIndex]);
        while(map[lastIndex] != lastIndex) {
            lastIndex = map[lastIndex];
            res.add(arr[lastIndex]);
        }
        Collections.reverse(res);
        return res;
    }
}
