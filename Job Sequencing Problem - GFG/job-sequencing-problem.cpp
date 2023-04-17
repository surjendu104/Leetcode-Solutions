//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    static bool comp(Job &a, Job &b) {
        return a.profit>b.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        int maxDesdline = INT_MIN;
        for(int i = 0;i<n;i++) {
            maxDesdline = max(maxDesdline, arr[i].dead);
        }
        
        vector<int> v(maxDesdline+1,-1);
        int k,cnt = 0,maxProfit = 0;
        for(int i = 0;i<n;i++) {
            for(int j = arr[i].dead;j>0;j--) {
                if(v[j]==-1){
                    v[j] = 1;
                    cnt++;
                    maxProfit+=arr[i].profit;
                    break;
                }
            }
        }
        
        return {cnt,maxProfit};
    } 
};

// 4
// 1 2 100 2 1 19 3 2 27 4 1 25 5 1 15

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends