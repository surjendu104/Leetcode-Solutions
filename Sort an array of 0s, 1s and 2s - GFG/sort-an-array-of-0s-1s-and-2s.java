//{ Driver Code Starts
//Initial template for Java

import java.io.*;
import java.util.*;


// } Driver Code Ends
//User function template for Java

class Solution
{
    static void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    public static void sort012(int a[], int n)
    {
        int i = 0, j = 0, k = n-1;
        int mid = 1;
        while(j <= k) {
            if(a[j] < mid) {
                // swap(a, a[j], a[i]);
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                i++;j++;
            }else if(a[j] > mid) {
                // swap(a, a[j], a[k]);
                int tmp = a[k];
                a[k] = a[j];
                a[j] = tmp;
                k--;
            }else j++;
        }
    }
}

//{ Driver Code Starts.

class GFG {
    
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
        while(t-->0){
            int n = Integer.parseInt(br.readLine().trim());
            int arr[] = new int[n];
            String inputLine[] = br.readLine().trim().split(" ");
            for(int i=0; i<n; i++){
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            Solution ob=new Solution();
            ob.sort012(arr, n);
            StringBuffer str = new StringBuffer();
            for(int i=0; i<n; i++){
                str.append(arr[i]+" ");
            }
            System.out.println(str);
        }
    }
}


// } Driver Code Ends